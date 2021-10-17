class Solution {
public:
    void bfs(int src, vector<vector<int>> &graph, vector<int> &dist) {
        int layer = 0;
        vector<int> seen(dist.size());
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            ++layer;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (seen[v]) continue;
                    seen[v] = 1;
                    dist[v] = layer;
                    q.push(v);
                }
            }
        }
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n+1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> dist1(n+1), distn(n+1);
        bfs(1, graph, dist1);
        bfs(n, graph, distn);
        set<int> s;
        s.insert(dist1[n]);
        for (int i = 2; i <= n; ++i)
            s.insert(dist1[i] + distn[i]);
        s.erase(s.begin());
        int t = *s.begin();
        int q = 0;
        for (int i = 0; i < t; ++i) {
            q += time;
            if (i == t-1) return q;
            bool red = (q / change) % 2 == 1;
            if (red) q += change - (q % change);
        }
        return -1;
    }
};
