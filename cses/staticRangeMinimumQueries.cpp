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
        int L, R; cin >> L >> R;
        cout << rmq.query(L-1, R-1) << endl;
    }
}
