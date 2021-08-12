class Solution {
public:
    int M, N;
    vector<vector<int>> dp;
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int dfs(int r, int c, vector<vector<int>>& m) {
        if (dp[r][c] != -1) return dp[r][c];
        int count = 0;
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (m[x][y] > m[r][c]) {
                dp[r][c] = max(dp[r][c], 1 + dfs(x, y, m));
                ++count;
            }
        }
        if (count == 0) dp[r][c] = 1;
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        dp.assign(M, vector<int>(N, -1));
        int ans = 0;
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                ans = max(ans, dfs(r, c, matrix));
            }
        }
        return ans;
    }
};
