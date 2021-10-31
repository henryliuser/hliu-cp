class Solution {
public:
    bool seen[101][101] = {};
    int dirs[8][2] = {
        {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int depth = 1;
        int M = grid.size();
        int N = grid[0].size();
        queue<pair<int, int>> q;
        if (grid[0][0] == 1) return -1;
        if (M == 1 && N == 1) return 1;
        q.push({0,0});
        while (!q.empty()) {
            ++depth;
            int sz = q.size();
            while (sz--) {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for (auto d : dirs) {
                    int r = x + d[0];
                    int c = y + d[1];
                    if (r < 0 || r >= M || c < 0 || c >= N)
                        continue;
                    if (seen[r][c] || grid[r][c] == 1)
                        continue;
                    if (r == M-1 && c == N-1)
                        return depth;
                    seen[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        return -1;
    }
};
