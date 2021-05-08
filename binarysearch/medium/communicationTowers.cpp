struct DSU {
    int count = 0;
    unordered_map<int, int> parent, size;
    void add(int a) {
        if (parent.count(a)) return;
        parent[a] = a;
        size[a] = 1;
        count++;
    }
    bool Union(int a, int b) {
        add(a); add(b);
        a = Find(a), b = Find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        size[b] += size[a];
        count--;
        return true;
    }
    int Find(int a) {
        if (a == parent[a]) return a;
        return parent[a] = Find(parent[a]);
    }
};

int solve(vector<vector<int>>& matrix) {
    DSU uf;
    int N = matrix.size();
    int M = matrix[0].size();
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (matrix[r][c])
                uf.Union(r, -c-1);
        }
    }
    return uf.count;
}
