// https://atcoder.jp/contests/abc239/tasks/abc239_e
// classic subtree queries. use euler tour method
// then binary search + mergeSortTree
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e5 + 5;

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
    ll query(ll x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    ll query(ll x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar)
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
        int mid = (tl + tr) / 2;
        ll ql = query(x, al, ar, v*2, tl, mid);
        ll qr = query(x, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<ll> &v)
        : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
};

int N, Q, a, b;
vector<vector<int>> adj;

int tin = 0;
int st[MXN], en[MXN];
void dfs(int u, int p) {
    st[u] = tin++;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    en[u] = tin-1;
}

template <class seg>
ll qry(int l, int r, int k, seg &s) {
    ll lo = 0, hi = 1e9;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        int gt = s.query(mid, l, r);  // # greater than
        if (gt < k) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    adj.resize(N+1);
    vector<ll> X(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> X[i];
    for (int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i)
        A[st[i]] = X[i];

    MergeTree seg(N+1, A);
    while (Q--) {
        cin >> a >> b;
        ll res = qry(st[a], en[a], b, seg);
        cout << res << '\n';
    }
}
