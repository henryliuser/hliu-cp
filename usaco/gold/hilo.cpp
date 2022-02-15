// http://usaco.org/index.php?page=viewproblem2&cpid=1162
// really good question
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

struct SegTree {
    int N;
    vector<pi> T;
    void upd(int x, int L, int R) { update(x,1,0,N-1,L,R); }
    void update(int val, int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return;
        if (lq <= l && r <= rq)
            T[v][0] += val,
                    T[v][1] += val;
        else {
            int mid = (l+r) / 2;
            if(T[v][1] != 0){
                update(T[v][1], v*2, l, mid, l, mid);
                update(T[v][1], v*2+1, mid+1, r, mid+1, r);
                T[v][1] = 0;
            }
            update(val, v*2, l, mid, lq, rq);
            update(val, v*2+1, mid+1, r, lq, rq);
        }
    }
    int query(int L, int R) { return query(1,0,N-1,L,R); }
    int query(int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return 0;
        if (lq <= l && r <= rq) return T[v][0];
        int mid = l + (r-l)/2;
        if (T[v][1] != 0) {
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> P(N);
    for (int &x : P) cin >> x;

    set<int> vis;
    int left, right;  // current range
    SegTree hi(N), ans(N);
    hi.upd(1, 0, P[0]-1);  // initialize hi's
    vis.insert(P[0]);
    for (int i = 1; i < N; ++i) {
        auto it = vis.upper_bound(P[i]);
        if (it == end(vis)) right = N;
        else right = *it;
        if (it == begin(vis)) left = 0;
        else left = *(--it);
        ++left, --right;
        // at this point, the range (left, right) will be affected.
        // they currently all have the same hi value, v.
        int y = P[i];
        int v = hi.query(y,y);
        ans.upd(!!v, y, right);  // everyone here gains a hilo if they had a hi
        hi.upd(-v, left, right);    // clear everyone's hi's
        hi.upd(1, left, y-1);      // assign new hi's generated
        vis.insert(y);
    }
    for (int x = 0; x <= N; ++x)
        cout << ans.query(x,x) << '\n';
}
