#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int N;
    vector<ll> &A, T;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);
        }
    }
    ll query(int L, int R) { return query(L, R, 1, 0, N-1); }
    ll query(int al, int ar, int v, int tl, int tr) {
        if (al > ar) return LLONG_MAX;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        ll ql = query(al, min(mid, ar), v*2, tl, mid);
        ll qr = query(max(mid+1, al), ar, v*2+1, mid+1, tr);
        return min(ql, qr);
    }
    void update(int i, int val) { update(i, val, 1, 0, N-1); }
    void update(int i, int val, int v, int tl, int tr) {
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);
        }
    }
    SegTree(int n, vector<ll> &v)
        : A(v), N(n), T(n*4) { build(1, 0, N-1); }
};

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    SegTree rmq(N, A);
    while (Q--) {
        int T, L, R; cin >> T >> L >> R;
        if (T == 1) rmq.update(L-1, R);
        if (T == 2) cout << rmq.query(L-1, R-1) << "\n";
    }
}
