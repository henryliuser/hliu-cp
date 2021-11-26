struct SegTree {
    int N;
    vector<int> &A, T;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = T[v*2] ^ T[v*2+1];
        }
    }
    int query(int L, int R) { return query(L,R,1,0,N-1); }
    int query (int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar) return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(al, ar, v*2, tl, mid);
        int qr = query(al, ar, v*2+1, mid+1, tr);
        return ql ^ qr;
    }
    SegTree(int n, vector<int> &a)
        : N(n), A(a), T(4*n) { build(1,0,N-1); }
};

vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size();
    int Q = queries.size();
    if (!Q) return {};
    vector<int> ans(Q);
    SegTree seg(N, nums);
    for (int i = 0; i < Q; ++i) {
        auto &q = queries[i];
        ans[i] = seg.query(q[0], q[1]);
    }
    return ans;
}
