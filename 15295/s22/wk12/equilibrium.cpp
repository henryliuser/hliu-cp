// https://codeforces.com/problemset/problem/1556/E
// strange insight but nice question
// conditions for -1: subarray sum != 0, "balance" ever goes negative at some point
// otherwise, answer is max balance
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
const ll INF = 1e18+5;

#define answer(x) {       \
    cout << (x) << '\n';  \
    continue;             \
}

struct SegTree {
    int N;
    vector<ll> &A;
    vector<pll> T;
    void build(int v, int tl, int tr) {
        // v: tree index, tl/tr: tree bounds
        if (tl == tr) T[v] = {A[tl], A[tl]};
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v][0] = min(T[v*2][0], T[v*2+1][0]);
            T[v][1] = max(T[v*2][1], T[v*2+1][1]);
        }
    }
    ll query(int al, int ar, int type) { return query(al, ar, 1, 0, N-1, type); }
    ll query(int al, int ar, int v, int tl, int tr, int type) {
        // al/ar: arr bounds
        if (al > ar) {
            ll m = (type) ? -1 : 1;
            return m * INF;
        }
        if (al == tl && ar == tr) return T[v][type];
        int mid = (tl + tr) / 2;
        ll ql = query(al, min(ar, mid), v*2, tl, mid, type);
        ll qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr, type);
        if (type == 0) return min(ql, qr);
        if (type == 1) return max(ql, qr);
        return 69;
    }
    SegTree(int n, vector<ll>& a)
        : N(n), A(a), T(4*n) { build(1, 0, N-1); }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N), D(N+1);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;
    for (int i = 1; i <= N; ++i) {
        D[i] = B[i-1] - A[i-1];
        D[i] += D[i-1];
    }

    SegTree seg(N+1, D);
    // query types = {0:min, 1:max}
    for (int l,r, i=0; i < Q; ++i) {
        cin >> l >> r;
        if (D[r] - D[l-1]) answer(-1);
        ll smin = seg.query(l, r, 0);
        if (smin - D[l-1] < 0) answer(-1);
        ll smax = seg.query(l, r, 1);
        answer(smax - D[l-1]);
    }
}
