class Solution {
public:
    long long modPow(long long x, long long y, int m) {
        if (y == 0) return 1;
        auto p = modPow(x, y / 2, m);
        return p * p * (y % 2 ? x : 1) % m;
    }

    unordered_set<long long> rabinKarp(
        vector<int>& src,
        int m, int b, long long q)
    {
        long long t = 0, d = 1 << b;
        long long h = modPow(2, b*m-b, q);
        unordered_set<long long> hashes;
        for (int i = 0; i < m; ++i) {
            t = (d * t + src[i]) % q;
            t = (t+q) % q;
        }
        hashes.insert(t);
        for (int i = 0; i < src.size() - m; ++i) {
            t = (d * (t - src[i] * h) + src[i+m]) % q;
            t = (t+q) % q;
            hashes.insert(t);
        }
        return hashes;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        long long q = 1e9+7;
        int M = nums1.size();
        int N = nums2.size();
        int lo = 0, hi = min(M, N);
        while (lo < hi) {
            int mid = ceil((lo+hi)/2.0);
            auto rk1 = rabinKarp(nums1, mid, 7, q);
            auto rk2 = rabinKarp(nums2, mid, 7, q);
            if (rk1.size() > rk2.size()) swap(rk1, rk2);
            bool ct = 0;
            for (auto it : rk1) {
                if (rk2.count(it)) {
                    ct = 1;
                    break;
                }
            }
            if (ct) lo = mid;
            else hi = mid-1;
        }
        return lo;
    }
};
