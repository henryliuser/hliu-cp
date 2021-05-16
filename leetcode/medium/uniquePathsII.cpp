class Solution {
public:
    // O(MN) time, O(N) space
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<int> dp(N); dp[0] = 1;
        int last = 0;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                dp[c] = (!obstacleGrid[r][c]) ? dp[c] + last : 0;
                last = dp[c];
            }
            last = 0;
        }
        return dp[N-1];
    }

    // O(MN) time, O(MN) space
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        dp[0][1] = 1;
        for (int r = 1; r <= M; r++)
            for (int c = 1; c <= N; c++)
                if (!obstacleGrid[r-1][c-1])
                    dp[r][c] += dp[r-1][c] + dp[r][c-1];

        return dp[M][N];
    }
};
