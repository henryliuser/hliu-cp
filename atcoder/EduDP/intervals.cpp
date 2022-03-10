// https://atcoder.jp/contests/dp/tasks/dp_w
// dp is a range add range max query segtree
// sweep line over the bits
// dp[i] = best value possible in prefix [0...i], IF I-TH BIT IS TAKEN
// we want to look for the best j, as in previous bit taken
// ans = max(dp)
// sweep line x from left to right, over all the bits
// when x enters some range (L[i], R[i], A[i])
// we now say that, if you take the previous bit j
// to be ANY bit in the range (0, x-1), you will incur A[i] change in score
// WHILE x stays in that range (L[i], R[i]), that ^^ property still holds
// because if the previous bit is to the left of L[i], then we incur A[i]
// when x fully clears the interval, x == R[i]+1, then
// the property no longer holds. Choosing the previous bit to be (0, L[i]-1)
// will no longer yield A[i] change in score.
// at each x, record the best possible score in dp[x]
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll MXN = 2e5+5;
using pl = pair<int,ll>;
const ll INF = 1e18;

template<class T> struct LazySeg {
    int sz = 1;
    vector<T> t, lz;
    const T BASE = -INF;
    T comb(T a, T b) { return max(a, b); }

    void init(int n) {
        while (sz < n) sz <<= 1;
        t.assign(2*sz, 0), lz.assign(2*sz, 0);
    }
    void push(int v, int l, int r) {
        t[v] += lz[v];
        if (l != r)
            lz[v * 2] += lz[v],
            lz[v*2+1] += lz[v];
        lz[v] = 0;
    }
    void update(int ql, int qr, T x) { update(ql, qr, x, 1, 0, sz-1); }
    void update(int ql, int qr, T x, int v, int l, int r) {
        push(v, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && qr >= r) {
            lz[v] += x;
            return void( push(v, l, r) );
        }
        int m = (l+r)/2;
        update(ql, qr, x, v*2, l, m);
        update(ql, qr, x, v*2+1, m+1, r);
        t[v] = comb( t[v*2], t[v*2+1] );
    }
    T query(int ql, int qr) { return query(ql, qr, 1, 0, sz-1); }
    T query(int ql, int qr, int v, int l, int r) {
        push(v, l, r);
        if (ql > r || qr < l) return BASE;
        if (ql <= l && qr >= r) return t[v];
        int m = (l+r)/2;
        T zl = query(ql, qr, v*2, l, m);
        T zr = query(ql, qr, v*2+1, m+1, r);
        return comb(zl, zr);
    }
};

int N, M;
LazySeg<ll> dp;
ll add[MXN] = {};
vector<pl> occ[MXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (ll l,r,a, i=0; i < M; ++i) {
        cin >> l >> r >> a;
        occ[r].emplace_back(l,a);
        add[l] += a;
    }
    dp.init(N+2);
    for (int x = 1; x <= N+1; ++x) {
        dp.update(0, x-1, add[x]);
        for (auto [l,a] : occ[x-1])
            dp.update(0, l-1, -a);

        ll res = dp.query(0, x-1);
        dp.update(x, x, res);
    }
    cout << dp.query(0, N+1) << '\n';
}
