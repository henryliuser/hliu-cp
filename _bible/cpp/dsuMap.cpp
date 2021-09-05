struct DSU {
    int count = 0;
    unordered_map<int, int> parent, size; // Union by Size
    void Add(int a) {
        if (parent.count(a)) return;
        parent[a] = a;
        size[a] = 1;
        count++;
    }
    bool Union(int a, int b) { // return on success
        Add(a), Add(b);
        a = Find(a), b = Find(b);
        if (a == b) return false; // cycle (undirected)
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b]; // size[b] not used after
        count--;
        return true;
    }
    int Find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = Find(parent[v]);
    }   // path compression
};
