struct CentroidDecomposition {
    int N;
    const int INF = 1e9 + 5;
    vector<set<int>> adj;
    vector< map<int,int> > dist;
    vector<int> sz, par, ans;

    void init(int n) {
        N = n;
        adj.resize(N);
        dist.resize(N);
        ans.assign(N, INF);
    }
    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int dfs(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u])
            if (v != p)
                sz[u] += dfs(v, u);
        return sz[u];
    }
    int centroid(int u, int p, int n) {
        for (int v : adj[u])
            if (v != p && sz[v] > n/2)
                return centroid(v, u, n);
        return u;
    }
    void dfs2(int u, int p, int c, int d) {  // build distance
        dist[c][u] = d;
        for (int v : adj[u])
            if (v != p)
                dfs2(v, u, c, d+1);
    }
    void build(int u, int p) {
        int n = dfs(u, p);
        int c = centroid(u, p, n);
        if(p == -1) p = c;
        par[c] = p;
        dfs2(c, p, c, 0);

        vector<int> tmp(adj[c].begin(), adj[c].end());
        for(auto v : tmp) {
            adj[c].erase(v); adj[v].erase(c);
            build(v, c);
        }
    }
    void update(int u) {
        for(int v = u; v != 0; v = par[v])
            ans[v] = min(ans[v], dist[v][u]);
    }
    int query(int u) {
        int res = INF;
        for(int v = u; v != 0; v = par[v])
            res = min(res, ans[v] + dist[v][u]);
        return mn;
    }
};
