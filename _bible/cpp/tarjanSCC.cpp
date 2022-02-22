struct Tarjan {
    int N;
    int T = 0, C = 1;
    vector<int> path;
    vector<bool> curr;
    vector<int> disc, low, scc;
    vector<vector<int>> &adj;

    void dfs(int u) {
        curr[u] = true;
        int i = path.size();
        path.push_back(u);
        disc[u] = low[u] = T++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {  // if not visited
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (curr[v])  // genius part
                low[u] = min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {  // found an SCC
            int id = C++;
            for (int j = i; j < path.size(); ++j) {
                scc[path[j]] = id;
                curr[path[j]] = false;
            }
            path.resize(i);
        }
    }

    int operator[](int i) { return scc[i]; }

    void init(int n) {
        adj.resize(n);
        scc.resize(n);
        low.assign(n, -1);
        disc.assign(n, -1);
        curr.assign(n, 0);
    }

    Tarjan( vector<vector<int>> &g ) : adj(g) {
        N = g.size();
        init(N);
        for (int i = 1; i <= N; ++i)
            if (disc[i] == -1)
                dfs(i);
    }
};
