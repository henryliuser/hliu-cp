struct SegTree {
    int N;
    vector<ll> T, &A;  // tree array, array reference
    void build(int v, int tl, int tr) {
        // v: tree index, tl/tr: tree bounds
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);  // adjust
        }
    }
    ll query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    ll query(int al, int ar, int v, int tl, int tr) {
        // al/ar: arr bounds
        if (al > ar) return 0;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        ll ql = query(al, min(ar, mid), v*2, tl, mid);
        ll qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return min(ql, qr);  // adjust
    }
    void update(int i, ll val) { update(i, val, 1, 0, N-1); }
    void update(int i, ll val, int v, int tl, int tr) {
        // i: arr index, val: new value
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);  // adjust
        }
    }
    SegTree(int n, vector<int>& a)
        : N(n), A(a), T(4*n) { build(1, 0, N-1); }
};
