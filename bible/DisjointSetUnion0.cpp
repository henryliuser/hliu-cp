struct DSU {
    int count;
    vector<int> parent, size; // Union by Size
    DSU(int N) : count(N), parent(N, -1), size(N, 1) {}
    bool Union(int a, int b) { // return on success
        a = Find(a), b = Find(b);
        if (a == b) return false; // cycle (undirected)
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b]; // size[b] not used after
        count--;
        return true;
    }
    int Find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = Find(parent[v]);
    }   // path compression
};
