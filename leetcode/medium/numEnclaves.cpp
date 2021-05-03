class Solution {
public:

    int N, M;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (grid[r][c] != 1) return;
        grid[r][c] = 0;
        for (auto d : dirs) {
            int x = r + d.first, y = c + d.second;
            if (x >= 0 && x < N && y >= 0 && y < M)
                dfs(x, y, grid);
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        N = grid.size(), M = grid[0].size();
        for (int z = 0; z < N; z++) {
            dfs(z, 0, grid);
            dfs(z, M-1, grid);
        }
        for (int z = 0; z < M; z++) {
            dfs(0, z, grid);
            dfs(N-1, z, grid);
        }
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                ans += (grid[r][c] == 1);

        return ans;

    }
};
