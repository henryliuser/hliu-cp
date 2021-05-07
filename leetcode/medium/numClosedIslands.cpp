class Solution {
public:

    int n, m;
    vector<pair<int, int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (grid[r][c]) return;
        grid[r][c] = 1;
        for (auto& d : dirs) {
            int x = r + d.first, y = c + d.second;
            if (x >= 0 && x < n && y >= 0 && y < m)
                if (!grid[x][y])
                    dfs(x, y, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();

        for (int z = 0; z < n; z++)
            dfs(z, 0, grid), dfs(z, m-1, grid);

        for (int z = 0; z < m; z++)
            dfs(0, z, grid), dfs(n-1, z, grid);

        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (!grid[r][c]) {
                    ans++;
                    dfs(r,c,grid);
                }
        return ans;
    }
};
