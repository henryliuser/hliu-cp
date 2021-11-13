struct DSU {
    int count;
    vector<int> parent, size; // Union by Size
    DSU(int N) : count(N), parent(N,-1), size(N, 1) {}
    bool unite(int a, int b) { // return on success
        a = find(a), b = find(b);
        if (a == b) return false; // cycle (undirected)
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b]; // size[b] not used after
        count--;
        return true;
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }   // path compression
};

struct DSU {    // cool memory optimization
    int count;
    vector<int> psz;
    DSU(int n) : count(n), psz(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};
