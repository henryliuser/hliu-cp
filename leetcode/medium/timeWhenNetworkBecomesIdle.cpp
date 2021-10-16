class Solution {
public:
    int n;
    vector<int> dist;
    vector<bool> seen;
    vector<vector<int>> graph;
    void bfs() {
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        seen[0] = 1;
        int layer = 0;
        while (!q.empty()) {
            ++layer;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int x = q.front();
                q.pop();
                for (int y : graph[x]) {
                    if (seen[y]) continue;
                    seen[y] = 1;
                    dist[y] = layer;
                    q.push(y);
                }
            }
        }
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int ans = 0;
        n = patience.size();
        dist.resize(n);
        seen.resize(n);
        graph.resize(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs();
        for (int i = 1; i < n; ++i) {
            int d = dist[i];
            int p = patience[i];
            int rtt = 2 * d;
            int resends = ceil(rtt / (double)p) - 1;
            resends = max(resends, 0);

            ans = max(ans, resends*p + rtt);
        }
        return ans+1;
    }
};
