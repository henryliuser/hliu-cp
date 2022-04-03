// https://leetcode.com/problems/sum-of-scores-of-built-strings/
// rabin karp + binary search
using ll = long long;
using ull = unsigned long long;
struct PolyHash {
    // -------- Static variables --------
    static const int mod = (int)1e9+123; // prime mod of polynomial hashing
    static std::vector<int> pow1;        // powers of base modulo mod
    static std::vector<ull> pow2;        // powers of base modulo 2^64
    static int base;                     // base (point of hashing)
    static int mxPow;

    // --------- Static functons --------
    static inline int diff(int a, int b) {
    	// Diff between `a` and `b` modulo mod (0 <= a < mod, 0 <= b < mod)
        return (a -= b) < 0 ? a + mod : a;
    }

    // Generate random base in (before, after) open interval:
    static int gen_base(const int before, const int after) {
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::mt19937 mt_rand(seed);
        int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
        return base % 2 == 0 ? base-1 : base;
    }

    // -------------- Variables of class -------------
    std::vector<int> pref1; // Hash on prefix modulo mod
    std::vector<ull> pref2; // Hash on prefix modulo 2^64

    // Cunstructor from string:
    PolyHash(const std::string& s)
        : pref1(s.size()+1u, 0)
        , pref2(s.size()+1u, 0)
    {
        mxPow = max(mxPow, (int)s.size());
        assert(base < mod);
        const int n = s.size(); // Firstly calculated needed power of base:
        while ((int)pow1.size() <= n) {
            pow1.push_back(1LL * pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        for (int i = 0; i < n; ++i) { // Fill arrays with polynomial hashes on prefix
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }

    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline std::pair<int, ull> operator()(const int pos, const int len) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return {hash1, hash2};
    }
};
int PolyHash::mxPow = 0;
int PolyHash::base((int)1e9+7);
std::vector<int> PolyHash::pow1{1};
std::vector<ull> PolyHash::pow2{1};


class Solution {
public:
    ll sumScores(string s) {
        int N = s.size();
        PolyHash::mxPow = 0;
        PolyHash::pow1 = {1};
        PolyHash::pow2 = {1};
        PolyHash::base = PolyHash::gen_base(256, PolyHash::mod);

        ll ans = 0;
        PolyHash H(s);
        for (int i = 0; i < N; ++i) {
            ll lo = 0, hi = N-i;
            while (lo < hi) {
                int m = lo + (hi-lo+1) / 2;
                auto h0 = H(0, m);
                auto hI = H(i, m);
                if (h0 == hI) lo = m;
                else hi = m - 1;
            }
            ans += lo;
        }
        return ans;
    }
};
