using edge = tuple<int, int, int>;
// {weight, a, b}

int kruskal(int N, vector<edge> &edges) {
    DSU uf(N);
    int ans = 0;
    sort(begin(edges), end(edges));
    for (auto &e : edges) {
        auto [w,a,b] = e;
        if (uf.unite(a,b)) ans += w;
        if (uf.count == 1) break;
    }
    return ans;
}
