struct DSU {
    vector<int> parent(n);
    vector<int> size(n); // for Union by Size

    void make(int z)
    {
        parent[z] = v;
        size[z] = 1;
    }

    void union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find(int v)
    {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }   // path compression

};
