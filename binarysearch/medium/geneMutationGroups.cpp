struct DSU {
    int count;
    vector<int> parent, size;
    DSU (int N) : count(N), parent(N), size(N, 1) {
        while (--N >= 0) parent[N] = N;
    }
    bool Union(int a, int b) {
        a = Find(a), b = Find(b);
        if (a == b) return false; // cycle
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += b;
        count--;
        return true;
    }
    int Find(int a) {
        if (a == parent[a]) return a;
        return parent[a] = Find(parent[a]);
    }
};

string chars[4] = {"A", "C", "G", "T"};

int solve(vector<string>& genes) {
    int N = genes.size(), k = genes[0].length();
    DSU uf{N};
    unordered_map<string, int> st;
    for (int a = 0; a < N; a++) {
        string& g = genes[a];
        for (int z = 0; z < k; z++) {
            for (string& c : chars) {
                string q = g.substr(0, z) + c + g.substr(z+1, -1);
                // cout << q << endl;
                if (st.count(q)) uf.Union(a, st[q]);
            }
        }
        st[g] = a;
    }
    return uf.count;
}
