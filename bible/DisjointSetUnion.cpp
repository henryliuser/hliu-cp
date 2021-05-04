struct DSU {
    int count;
    vector<int> parent;
    vector<int> size; // Union by Size

    DSU(int N) : count(N), parent(N), size(N, 1) {
        for (int z = 0; z < N; z++) parent[z] = z;
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            count--;
        }
    }

    int Find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = Find(parent[v]);
    }   // path compression
};
