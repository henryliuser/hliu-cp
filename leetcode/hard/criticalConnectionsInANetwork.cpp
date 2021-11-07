class Solution {
public:
    int T = 0;
    vector<int> disc, low;
    vector<vector<int>> adj, ans;

    void tarjan(int u, int p = -1) {
        disc[u] = low[u] = T++;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (disc[v] != -1)
                low[u] = min(low[u], disc[v]);
            else {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    // (u -> v) is a bridge
                    ans.push_back( {u,v} );
                }
            }
        }
    }

    void init(int n) {
        adj.resize(n);
        low.resize(n);
        disc.assign(n, -1);
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        init(n);
        for (auto c : connections) {
            int a = min(c[0], c[1]);
            int b = max(c[0], c[1]);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        tarjan(0);
        return ans;
    }
};
