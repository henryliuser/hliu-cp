class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        int dirs[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
        vector<vector<int>> ans(M, vector<int>(N, -1));

        queue<pair<int, int>> q;
        for (int r = 0; r < M; ++r)  {
            for (int c = 0; c < N; ++c) {
                if (!mat[r][c]) {
                    q.push({r, c});
                    ans[r][c] = 0;
                }
            }
        }

        while (!q.empty()) { // bfs
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (auto& d : dirs) {
                int r = x + d[0];
                int c = y + d[1];
                if (r >= 0 && r < M && c >= 0 && c < N) {
                    if (ans[r][c] == -1) {
                        q.push({r, c});
                        ans[r][c] = 1+ans[x][y];
                    }
                }
            }
        }
        return ans;
    }
};
