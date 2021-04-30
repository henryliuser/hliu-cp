class Solution {
public:

    int n, m;

    void bfs(int r, int c,
             vector<vector<bool>>& seen,
             vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push( {r, c} );
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            r = p.first, c = p.second;
            seen[r][c] = true;
            if (r-1 >= 0 && !seen[r-1][c] && grid[r-1][c] == '1')
                q.push( {r-1, c} );
            if (r+1 <  n && !seen[r+1][c] && grid[r+1][c] == '1')
                q.push( {r+1, c} );
            if (c-1 >= 0 && !seen[r][c-1] && grid[r][c-1] == '1')
                q.push( {r, c-1} );
            if (c+1 <  m && !seen[r][c+1] && grid[r][c+1] == '1')
                q.push( {r, c+1} );
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> seen(n, vector<bool>(m));
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++) {
                if (seen[r][c] || grid[r][c] == '0') continue;
                ans++;
                bfs(r, c, seen, grid);
            }
        return ans;
    }
};
