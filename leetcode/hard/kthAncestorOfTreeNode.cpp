class TreeAncestor {
public:
    int LOG;
    int up[50001][20];
    TreeAncestor(int n, vector<int>& parent) {
        memset(up, -1, sizeof up);
        LOG = ceil(log2(n));
        for (int v = 0; v < n; ++v)
            up[v][0] = parent[v];
        for (int j = 1; j <= LOG; ++j) {
            for (int v = 0; v < n; ++v)
                if (up[v][j-1] == -1) up[v][j] = -1;
                else up[v][j] = up[ up[v][j-1] ][j-1];
        }
    }

    int getKthAncestor(int v, int k) {
        for (int j = 0; j <= LOG; ++j) {
            if (k & (1 << j))
                v = up[v][j];
            if (v == -1) return -1;
        }
        return v;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
