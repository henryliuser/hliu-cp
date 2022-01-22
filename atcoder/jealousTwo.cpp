// https://atcoder.jp/contests/abc231/tasks/abc231_f
// sort A, mergetree on B
// count elements such that A is happy and B is happy
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define tup(t, x) array<t, x>

struct MergeTree {
    int N;
    vector<ll> &A;
    vector<vector<ll>> T;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = {A[tl]};
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v].resize(tr-tl+1);
            auto &L = T[v*2], &R = T[v*2+1];
            merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
        }
    }
    int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    int query(int x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar)
            return end(T[v]) - lower_bound(begin(T[v]), end(T[v]), x);
        int mid = (tl + tr) / 2;
        int ql = query(x, al, ar, v*2, tl, mid);
        int qr = query(x, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<ll> &v)
        : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
};

int main() {
    int N; cin >> N;
    vector<tup(ll,2)> G(N);
    for (int i = 0; i < 2*N; ++i)
        cin >> G[i%N][i>=N];
    sort(begin(G), end(G));
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i)
        A[i] = G[i][0], B[i] = G[i][1];

    ll ans = 0;
    MergeTree seg(N, B);
    for (int i = 0; i < N; ++i) {
        ll x = A[i], y = B[i];
        auto it = upper_bound(begin(A), end(A), x);
        int j = it - begin(A) - 1;
        ans += seg.query(y, 0, j);
    }
    cout << ans << '\n';
}
