class Solution {
public:
    int dp[2][3]{};
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        for (int i = 1; i <= N; ++i) {
            int t = i % 2;
            for (int c = 0; c < 3; ++c) {
                dp[t][c] = INT_MAX;
                for (int j = 0; j < 3; ++j) {
                    if (c == j) continue;
                    dp[t][c] = min(dp[t][c], dp[!t][j]);
                }
                dp[t][c] += costs[i-1][c];
            }
        }
        return *min_element(dp[N%2], dp[N%2] + 3);
    }
};
