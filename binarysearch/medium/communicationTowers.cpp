struct DSU {
    int count = 0;
    unordered_map<int, int> pr; // par + rank
    void add(int u) {
        if (pr.count(u)) return;
        pr[u] = -1;
        ++count;
    }
    bool unite(int u, int v) {
        add(u), add(v);
        u = find(u), v = find(v);
        if (u == v) return false;
        if (pr[u] > pr[v]) swap(u, v);
        pr[u] += pr[v];
        pr[v] = u;
        --count;
        return true;
    }
    int find(int u) {
        if (pr[u] < 0) return u;
        return pr[u] = find(pr[u]);
    }
};

int solve(vector<vector<int>>& matrix) {
    DSU uf;
    int N = matrix.size();
    int M = matrix[0].size();
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c)
            if (matrix[r][c])
                uf.unite(r, -c-1);

    return uf.count;
}
