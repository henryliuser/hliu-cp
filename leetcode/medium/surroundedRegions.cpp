class Solution {
public:

    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    int n, m;
    void dfs(int r, int c, vector<vector<char>>& board) {
        // mark, then later delete every 'O' that's not marked
        board[r][c] = 'M';
        for (auto& d : dirs) {
            int x = r + d.first, y = c + d.second;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (board[x][y] == 'O')
                    dfs(x, y, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int z = 0; z < n; z++) {
            if (board[z][0]   == 'O') dfs(z, 0, board);
            if (board[z][m-1] == 'O') dfs(z, m-1, board);
        }
        for (int z = 0; z < m; z++) {
            if (board[0][z]   == 'O') dfs(0, z, board);
            if (board[n-1][z] == 'O') dfs(n-1, z, board);
        }
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'M') board[r][c] = 'O';
            }
    }
};
