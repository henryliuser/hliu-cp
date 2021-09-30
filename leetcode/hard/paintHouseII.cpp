// Can do better, use PQ to keep track of just the 2 smallest.
class Solution {
public:
    int dp[20]{};
    int minCostII(vector<vector<int>>& costs) {
        int N = costs.size();
        int K = costs[0].size();
        vector<int> pm(K+2), sm(K+2);
        pm[0] = INT_MAX, pm[K+1] = INT_MAX;
        sm[0] = INT_MAX, sm[K+1] = INT_MAX;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < K; ++j)
                dp[j] = min(pm[j], sm[j+2]) + costs[i-1][j];
            for (int j = 1; j <= K; ++j) {
                pm[j] = min(pm[j-1], dp[j-1]);
                sm[K-j+1] = min(sm[K-j+2], dp[K-j]);
            }
        }
        return *min_element(dp, dp+K);
    }
};
