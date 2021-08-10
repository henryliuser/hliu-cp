class Solution {
public:
    int ans = 0;
    int M, N, numEmpty;
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    void dfs(int r, int c, vector<vector<int>>& grid, int len) {
        seen[r][c] = true;
        if (grid[r][c] == 2) {
            if (len == numEmpty) ++ans;
            seen[r][c] = false;
            return;
        }
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (!seen[x][y] && grid[x][y] != -1)
                dfs(x, y, grid, len+1);
        }
        seen[r][c] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx, sy;
        M = grid.size();
        N = grid[0].size();
        seen.assign(M, vector<bool>(N));
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                if (grid[r][c] == 1)
                    sx = r, sy = c;
                if (grid[r][c] != -1)
                    ++numEmpty;
            }
        }
        dfs(sx, sy, grid, 1);
        return ans;

    }
};
