// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
// same as ABC229 G - Longest Y
using ll = long long;
class Solution {
public:
    struct DistSum {
        vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
        DistSum(vector<ll> &a) {
            int n = a.size();
            for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
            for (int i = 1; i < n; ++i) {
                d[0][i] = (a[i] - a[i-1]) + d[0][i-1];  // gap-prev (psum of gaps)
                p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of gaps
                d[1][n-i-1] = (a[n-i] - a[n-i-1]) + d[1][n-i];
                p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
            }
        }
        ll query(int src, int i) {
            int q = (src > i);
            ll diff = p[q][i] - p[q][src];
            ll ogd = d[q][src];
            ll len = abs(src-i);
            return diff - ogd * len;
        }
    };
    int minMoves(vector<int>& A, int k) {
        vector<ll> B;
        int N = A.size();
        for (int i = 0; i < N; ++i)
            if (A[i]) B.push_back( i-B.size() );

        DistSum ds(B);
        int M = B.size();
        ll ans = INT_MAX;
        for (int i = 0; i < M-k+1; ++i) {
            int mid = i + k/2;
            ll a = ds.query(mid, i);
            ll b = ds.query(mid, i+k-1);
            ans = min(ans, a+b);
        }
        return ans;
    }
};
