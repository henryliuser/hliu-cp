class Solution {
public:
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
