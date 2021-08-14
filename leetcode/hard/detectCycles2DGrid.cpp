// intuition for don't go backwards is Snake game
// the only way to eat yourself is if you use a
// series of Up Left Down Right, never going opposite
// of previous move.
class Solution {
public:
    int M, N;
    int ans = 0;
    vector<vector<bool>> seen;
    int dirs[4][2] = {{0,1}, {-1,0}, {1,0}, {0,-1}};
    void dfs(int r, int c, int a, int b, vector<vector<char>>& g) {
        seen[r][c] = true;
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (g[x][y] != g[r][c]) continue;
            if (x == a && y == b) continue; // don't go backwards
            if (seen[x][y]) throw -1;
            else dfs(x, y, r, c, g);
        }
    }

    bool containsCycle(vector<vector<char>>& g) {
        M = g.size();
        N = g[0].size();
        seen.assign(M, vector<bool>(N));
        for (int c = 0; c < N; ++c) {
            for (int r = 0; r < M; ++r) {
                if (seen[r][c]) continue;
                try { dfs(r, c, r, c, g); }
                catch (...) { return true; }
            }
        }
        return false;
    }
};
