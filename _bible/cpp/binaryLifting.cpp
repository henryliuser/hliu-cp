struct BinaryLifting {
    int N, L, T = 0;
    vector<vector<int>> &adj, up;
    vector<int> in, out;  // time in, time out

    int msb(int x) {  // genius lol
        union { double a; int b[2]; };
        a = x;
        return (b[1] >> 20) - 1023;
    }

    void dfs(int u, int p) {
        in[u] = ++T;
        up[u][0] = p;
        for (int j = 1; j < L; ++j) {
            int q = up[u][j-1];
            if (q == -1) up[u][j] = -1;  // maybe adjust
            else up[u][j] = up[q][j-1];
        }

        for (int v : adj[u])
            if (v != p)
                dfs(v, u);
        out[u] = ++T;
    }

    inline bool isAncestor(int u, int v) {
        return (in[u] <= in[v] && out[v] <= out[u]);
    }

    int lca(int u, int v) {  // the least common ancestor of u and v
        if (isAncestor(u,v)) return u;
        if (isAncestor(v,u)) return v;
        for (int j = L-1; ~j; --j)
            if (!isAncestor(up[u][j], v))
                u = up[u][j];
        return up[u][0];
    }

    int operator() (int u, int k) {  // the k-th ancestor of u
        for (int j = 0; j < L; ++j)
            if (k & (1<<j))
                u = up[u][j];
        return u;
    }

    BinaryLifting ( vector<vector<int>> &e )
        : N(e.size()), adj(e), in(N), out(N) {
        L = 2 + msb(N);
        up.assign(N+1, vector<int>(L));
        dfs(1, 0);  // 1-indexed
        out[0] = ++T;
    }
};
