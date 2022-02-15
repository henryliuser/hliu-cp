// range add, point query
struct SegTree {
    int N;
    vector<pi> T;
    void upd(int x, int L, int R) { upd(x,1,0,N-1,L,R); }
    void upd(int val, int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return;
        if (lq <= l && r <= rq)
            T[v][0] += val,
            T[v][1] += val;
        else {
            int mid = (l+r) / 2;
            if (T[v][1]) {  // prop
                upd(T[v][1], v*2, l, mid, l, mid);
                upd(T[v][1], v*2+1, mid+1, r, mid+1, r);
                T[v][1] = 0;
            }
            upd(val, v*2, l, mid, lq, rq);
            upd(val, v*2+1, mid+1, r, lq, rq);
        }
    }
    int query(int L, int R) { return query(1,0,N-1,L,R); }
    int query(int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return 0;
        if (lq <= l && r <= rq) return T[v][0];
        int mid = (l+r) / 2;
        if (T[v][1]) {  // prop
            update(T[v][1], v*2, l, mid, l, mid);
            update(T[v][1], v*2+1, mid+1, r, mid+1, r);
            T[v][1] = 0;
        }
        int ql = query(v*2, l, mid, lq, rq);
        int qr = query(v*2+1, mid+1, r, lq, rq);
        return ql + qr;
    }
    SegTree(int n) {
        int t = n+1, c = 0;
        while (t) t>>=1, ++c;
        N = 1 << c, T.assign(1<<(c+1), {0,0});
    }
};
