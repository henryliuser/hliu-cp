class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n, vector<bool>(n));
        vector<int> deg(n, 0);
        for (auto& e : edges) {
            int a = e[0]-1, b = e[1]-1;
            adj[a][b] = true,
            adj[b][a] = true;
            deg[a] += 1;
            deg[b] += 1;
        }
        int ans = INT_MAX;
        for (int a = 0; a < n; a++) {
            for (int b = a+1; b < n; b++) {
                if (!adj[a][b]) continue; // optimization
                for (int c = b+1; c < n; c++) {
                    if (adj[a][c] && adj[b][c]) {
                        int tDeg = deg[a] + deg[b] + deg[c] - 6;
                        ans = min(ans, tDeg);
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
