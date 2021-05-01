class Solution {
public:

    int n, m;
    vector<pair<int, int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    void bfs(int r, int c, vector<vector<char>>& grid) {
        if (grid[r][c] == '0') return;
        queue<pair<int, int>> q;
        q.push( {r, c} );
        grid[r][c] = '0';
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            r = p.first, c = p.second;
            for (pair<int, int> d : dirs) {
                int x = r+d.first, y = c+d.second;
                if (x >= 0 && x < n && y >= 0 && y < m)
                    if (grid[x][y] == '1') {
                        grid[x][y] = '0';
                        q.push( {x, y} );
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '0') continue;
                ans++;
                bfs(r, c, grid);
            }
        return ans;
    }
};
