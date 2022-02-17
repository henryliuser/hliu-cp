// https://codeforces.com/problemset/problem/1638/E
// use ordered set of monochrome intervals to keep track of colors
// use range add, point query seg tree to maintain sums
// maintain ll lazy[N+1] to track pending updates
// by immediately subtracting lazy[c] on a color update,
// you are accounting for the delta in lazy[c] when u query or update again
// -lazy[c] @ t1 ... lazy[c] += 5 ... query(i) + lazy[c] @ t2
//
// O(1)
// add(c,x) -> lazy[c] += x
//
// O(log N) amortized
// every interval u walk over gets deleted
// # of intervals can't ever increase by more than 2
// total complexity therefore bounded by total insertions
// update(l,r,c) ->
//    for all intersecting intervals (i,j,k)
//         split into new intervals logically
//         seg.update( -lazy[k] , [section that's changing color] )
//    seg.update( lazy[c], l, r );
//
// O(log N)
// query(i) -> find i's color c, then return `seg.query(i,i) + lazy[c]`
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9+5;

// range add, point query
struct SegTree {
    int N;
    vector<array<ll,2>> T;
    void upd(ll dx, int L, int R) { upd(dx,1,0,N-1,L,R); }
    void upd(ll dx, int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return;
        if (lq <= l && r <= rq)
            T[v][0] += dx,
            T[v][1] += dx;
        else {
            int mid = (l+r) / 2;
            if (T[v][1]) {  // prop
                upd(T[v][1], v*2, l, mid, l, mid);
                upd(T[v][1], v*2+1, mid+1, r, mid+1, r);
                T[v][1] = 0;
            }
            upd(dx, v*2, l, mid, lq, rq);
            upd(dx, v*2+1, mid+1, r, lq, rq);
        }
    }
    ll query(int L, int R) { return query(1,0,N-1,L,R); }
    ll query(int v, int l, int r, int lq, int rq) {
        if (l > r || lq > r || rq < l) return 0;
        if (lq <= l && r <= rq) return T[v][0];
        int mid = (l+r) / 2;
        if (T[v][1]) {  // prop
            upd(T[v][1], v*2, l, mid, l, mid);
            upd(T[v][1], v*2+1, mid+1, r, mid+1, r);
            T[v][1] = 0;
        }
        ll ql = query(v*2, l, mid, lq, rq);
        ll qr = query(v*2+1, mid+1, r, lq, rq);
        return ql + qr;
    }
    void init(int n) {
        int t = n+1, c = 0;
        while (t) t>>=1, ++c;
        N = 1 << c, T.assign(1<<(c+1), {0,0});
    }
};

using iv = array<int, 3>;
int N, Q;
string t;
SegTree seg;
set<iv> ivals;  // sorted monochrome intervals
vector<ll> lazy;

void add() {
    ll c, x; cin >> c >> x;
    lazy[c] += x;
}

void color() {
    int l, r, c;
    cin >> l >> r >> c;
    auto it = ivals.upper_bound( {r,INF,-1} );
    vector<iv> del, add;
    while (1) {
        if (it == begin(ivals)) break;
        iv x = *(--it);
        if (x[1] < l) break;
        ll dv = lazy[x[2]];
        int L = max(l, x[0]), R = min(r, x[1]);
        if (x[0] < l)
            add.push_back( {x[0], l-1, x[2]} );
        if (x[1] > r)
            add.push_back( {r+1, x[1], x[2]} );
        seg.upd(dv, L, R);
        del.push_back(x);
    }
    for (iv &x : del) ivals.erase(x);
    for (iv &x : add) ivals.insert(x);
    ivals.insert( {l,r,c} );
    seg.upd(-lazy[c], l, r);
}

ll query() {
    int i; cin >> i;
    auto it = ivals.upper_bound( {i,INF,-1} );
    if (it != begin(ivals)) --it;
    int c = (*it)[2];
    return seg.query(i,i) + lazy[c];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    seg.init(N+1);
    lazy.assign(N+1, 0);
    ivals.insert( {1, N, 1} );
    while (Q--) {
        cin >> t;
        if (t[0] == 'A') add();
        if (t[0] == 'C') color();
        if (t[0] == 'Q') cout << query() << '\n';
    }
}
