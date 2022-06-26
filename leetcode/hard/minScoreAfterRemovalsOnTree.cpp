// https://leetcode.com/contest/weekly-contest-299/problems/minimum-score-after-removals-on-a-tree/
// nice question. separate into components and do DP
#define all(x) begin(x), end(x)
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> comp, par, dp;

    int dfs(int u, int p, int c, vector<int> &nums) {
        par[u] = p;
        comp[u] = c;
        dp[u] = nums[u];
        for (int v : adj[u])
            if (v != p && comp[v] == -1)
                dp[u] ^= dfs(v, u, c, nums);
        return dp[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int ans = 1e9 + 5;
        int N = nums.size();

        for (int i = 0; i < N-1; ++i) {
            comp.assign(N, -1);
            par.assign(N, -1);
            dp.assign(N, 0);
            adj.assign(N, vector<int>());
            for (int j = 0; j < N-1; ++j) {
                if (i == j) continue;
                int u = edges[j][0], v = edges[j][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            int c = 0;
            for (int u = 0; u < N; ++u)
                if (comp[u] == -1)
                    dfs(u, u, c++, nums);

            array<int, 3> XOR{};
            for (int u = 0; u < N; ++u)
                XOR[ comp[u] ] ^= nums[u];

            for (int j = i+1; j < N-1; ++j) {
                auto res = XOR;
                int u = edges[j][0], v = edges[j][1];
                if (par[u] == v) swap(u,v);
                int c = comp[u];
                res[c] ^= dp[v];
                res[2] ^= dp[v];
                int mx = *max_element( all(res) );
                int mn = *min_element( all(res) );
                ans = min(ans, mx-mn);
            }
        }
        return ans;
    }
};
