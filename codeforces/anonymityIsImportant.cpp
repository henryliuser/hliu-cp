// https://codeforces.com/problemset/problem/1641/C
// pretty complicated to understand imo.
// first of all, we can NEVER confirm healthy unless explicitly given
// maintain a set of potentially sick
// on a query 0 L R 0, remove [L,R] from the set
// the total complexity of these removals is bounded by O(N log N)
// maintain a point set, RMQ seg tree where each slot i keeps track of
// some index j such that we've seen a query 0 i j 1
// to answer type 1 query, if they aren't in the set then they're healthy
// otherwise, on a point query at i:
// let it = maybe.lower_bound(i)
// let L = prev(it) -- *L = idx of the closest maybe to the left of i
// let R = next(it) -- *R = idx of the closest maybe to the right of i
// notice that the interval [L+1, R-1] must be all confirmed healthy, except i
// i is confirmed sick IFF: rmq(L+1, i) < R
//
// DIAGRAM  |  O = healthy,   X = sick,   ? = maybe
//
//   L       i   R
// 0 1 2 3 4 5 6 7  -- index
// ? ? H H H ? H ?  -- status     -> point query on i returns "NO"
// 8 8 6 8 8 8 8 8  -- seg tree
//
// basically, i is an ISOLATED ?. We can confirm it to be sick IFF
// it is the only remaining ? in some Maybe range [A,B] where this range
// BEGINS in [L+1, i] and ENDS before R. If those Maybe ranges stretch beyond
// R, then we dont have enough information to confirm i.
// reminder that L < A <= i, and q can never be < i, because otherwise
// we've been given contradicting information. because the range [L+1, i-1]
// is CONFIRMED to be healthy already by our definition, so q >= i
// if q == i then we have the following case:
// 0 2 5 1
// 0 2 4 0
// so i=5 is an isolated ? and is confirmed to be sick
// if q > i && q < R we have
// 0 2 7 1
// 0 2 4 0
// 0 6 7 0
// so i=5 is again an isolated ? and confirmed to be sick
// if q > R then we have:
// 0 2 8 1
// 0 2 4 0
// 0 6 7 0
// then i=5 is isolated, but on the range [2,8] we dont know if i=5 or i=8
// or both 5 and 8 are sick.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
const int INF = 1e8;


struct SegTree {
    int N;
    vector<int> T;
    void build(int v, int tl, int tr) {
        // v: tree index, tl/tr: tree bounds
        if (tl == tr) T[v] = INF;
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);  // adjust this
        }
    }
    int query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    int query(int al, int ar, int v, int tl, int tr) {
        // al/ar: arr bounds
        if (al > ar) return INF;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(al, min(ar, mid), v*2, tl, mid);
        int qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return min(ql, qr);
    }
    void update(int i, int val) { update(i, val, 1, 0, N-1); }
    void update(int i, int val, int v, int tl, int tr) {
        // i: arr index, val: new value
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);  // adjust this
        }
    }
    void init(int n) {
        N = n, T.resize(4*n);
        build(1, 0, N-1);
    }
};

int N, Q;
SegTree seg;
set<int> maybe;
int t, l, r, x;

void upd() {
    cin >> l >> r >> x;
    if (x == 1) {
        int q = seg.query(l, l);
        if (q <= r) return;
        seg.update(l, r);
    }
    if (x == 0) {
        vector<int> del;
        auto it = maybe.lower_bound(l);
        while (1) {
            if (it == end(maybe)) break;
            if (*it > r) break;
            del.push_back(*it);
            ++it;
        }
        for (int d : del) maybe.erase(d);
    }
}

string qry() {
    cin >> x;
    if (!maybe.count(x)) return "NO";
    auto it = maybe.lower_bound(x);
    int i = *it;
    int L = -1, R = N+1;
    if (it != begin(maybe))     L = *prev(it);
    if (it != prev(end(maybe))) R = *next(it);
    int q = seg.query(L+1, i);
    if (q < R) return "YES";
    return "N/A";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    seg.init(N+5);
    for (int i = 1; i <= N; ++i)
        maybe.insert(i);

    while (Q--) {
        cin >> t;
        if (t == 0) upd();
        if (t == 1) cout << qry() << '\n';
    }
}
