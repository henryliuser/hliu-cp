// very intuitive binary search DFS
class Solution {
public:
    int M, N;
    int ans = INT_MAX;
    vector<vector<bool>> seen;
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    bool dfs(int r, int c, int maxT, int lim, vector<vector<int>>& grid) {
        seen[r][c] = true;
        if (maxT > lim) return false;
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= M || y < 0 || y >= N) continue;
            int mt = max(maxT, grid[x][y]);
            if (seen[x][y] || mt > lim) continue;
            if (x == M-1 && y == N-1) {
                ans = min(ans, mt);
                return true;
            }
            if (dfs(x, y, mt, lim, grid))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int lo = 0, hi = 1e5;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            seen.assign(M, vector<bool>(N));
            if (dfs(0,0,grid[0][0], mid, grid))
                hi = ans;
            else lo = mid+1;
        }
        return ans;
    }
};


// unintuitive PQ bfs
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
