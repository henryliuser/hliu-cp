// https://leetcode.com/problems/count-array-pairs-divisible-by-k/
// let g = gcd(A[i], k), it represents the max amount that A[i] contributes
// to the product with respect to k??
// count the number of times a multiple of g/k has appeared.
// update each factor.
// instead of counting all of the multiples of k/x, compress
// them all into the gcd
using ll = long long;
class Solution {
public:
    int gcd(int a, int b) {
        while (b)
            swap(a %= b, b);
        return a;
    }

    set<int> factorize(int n) {
        set<int> f;
        for (int x = 1; x*x <= n; ++x)
            if (n % x == 0) {
                f.insert(n / x);
                f.insert(x);
            }
        return f;
    }

    ll cnt[100001];
    ll coutPairs(vector<int>& A, int k) {
        int N = A.size();
        memset(cnt, 0, sizeof cnt);
        auto facs = factorize(k);

        ll ans = 0;
        for (int x : A) {
            int g = gcd(x, k);
            ans += cnt[k/g];
            for (int f : facs)
                if (g % f == 0)
                    ++cnt[f];
        }
        return ans;
    }
};
