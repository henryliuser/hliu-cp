class Solution {
public:

    int dirs[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        int N = grid.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> seen(N, vector<bool>(N));
        pq.push({-grid[0][0],{0,0}});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans = max(ans, -p.first);
            int i = p.second.first;
            int j = p.second.second;
            seen[i][j] = true;
            if (i == N-1 && j == N-1) return ans;
            for (auto& d : dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    if (!seen[x][y])
                        pq.push({-grid[x][y], {x, y}});
                }
            }
        }
        return -1;
    }
};
