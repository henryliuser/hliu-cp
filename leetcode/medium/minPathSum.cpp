class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(N+1, INT_MAX));
        dp[0][1] = 0;
        for (int r = 1; r <= M; ++r) {
            int t = r % 2;
            for (int c = 1; c <= N; ++c) {
                int val = grid[r-1][c-1];
                dp[t][c] = val + min(dp[!t][c], dp[t][c-1]);
            }
        }
        return dp[M%2][N];
    }
};
