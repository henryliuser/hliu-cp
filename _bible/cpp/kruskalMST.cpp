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

struct DSU {
    int count;
    vector<int> size, parent;
    DSU(int n) : count(n), size(n, 1), parent(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        --count;
        return true;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
};
