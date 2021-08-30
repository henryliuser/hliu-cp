// O(N + K) rolling hash
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int N = s.length();
        if (k >= N) return false;
        unordered_set<int> seen;
        int val = 0;
        for (int z = 0; z < k; ++z)
            val = 2*val + (s[z] - '0');
        seen.insert(val);
        for (int z = k; z < N; ++z) {
            int L = s[z-k] - '0';
            int R = s[z]   - '0';
            val = 2*(val-(L<<(k-1))) + R;
            seen.insert(val);
        }
        return seen.size() == (1 << k);
    }
};

// O(NK) brute force, slow
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int ans = 1 << k;
        int N = s.length();
        unordered_set<string> seen;
        for (int z = 0; z < N-k+1; ++z) {
            string q = s.substr(z, k);
            seen.insert(q);
        }
        return seen.size() == ans;
    }
};
