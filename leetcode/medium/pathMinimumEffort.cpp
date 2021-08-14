// very nice problem
// binary search on answer can be applied in many places
// O(MN log 1e6)
class Solution {
public:
    int M, N;
    vector<vector<bool>> seen;
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void dfs(int r, int c, int effort, int limit, vector<vector<int>>& h) {
        if (r == M-1 && c == N-1) throw effort;
        seen[r][c] = true;
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (seen[x][y]) continue;
            int diff = abs(h[x][y] - h[r][c]);
            int newEff = max(effort, diff);
            if (newEff > limit) continue;
            dfs(x,y, newEff, limit, h);
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();
        if (M == N && M == 1) return 0;
        int lo = 0, hi = 1e6;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            seen.assign(M, vector<bool>(N));
            seen[0][0] = true;
            try {
                dfs(0,0,0,mid,heights);
                lo = mid + 1;
            }
            catch (int e) {
                hi = e;
            }
        }
        return lo;
    }
};
