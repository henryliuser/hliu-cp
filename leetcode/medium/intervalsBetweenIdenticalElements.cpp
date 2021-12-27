// https://leetcode.com/contest/weekly-contest-273/problems/intervals-between-identical-elements/
using ll = long long;
class Solution {
public:
    struct DistSum {
        vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
        DistSum(vector<ll> &a) {
            int n = a.size();
            for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
            for (int i = 1; i < n; ++i) {
                d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
                p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of dists
                d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
                p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
            }
        }
        ll query(int src, int i) {
            int q = (src > i);
            ll diff = p[q][i] - p[q][src];
            ll cut = d[q][src];
            ll len = abs(src-i);
            return diff - cut * len;
        }
    };
    vector<ll> getDistances(vector<int>& arr) {
        int N = arr.size();
        vector<ll> ans(N);
        unordered_map<int, vector<ll>> mp;
        for (int i = 0; i < N; ++i)
            mp[ arr[i] ].push_back(i);

        for (auto &p : mp) {
            int x = p.first;
            auto &v = p.second;
            int M = v.size();

            DistSum ds(v);
            for (int i = 0; i < M; ++i) {
                int j = v[i];
                ans[j] += ds.query(i,0);
                ans[j] += ds.query(i,M-1);
            }
        }
        return ans;
    }
};
