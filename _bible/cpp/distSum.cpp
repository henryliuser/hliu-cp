struct DistSum {
    vector<ll> d[2], p[2];    // 0 left->right, 1 right->left
    DistSum(vector<ll> &a) {  // a : sorted positions
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
            p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of dists
            d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
            p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
        }
    }
    inline ll operator() (int src, int i) {  // sum of dists from src to i
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll cut = d[q][src];
        ll len = abs(src-i);
        return diff - cut * len;
    }
};
