// https://cses.fi/problemset/task/1077
// binary search a BIT
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using namespace std;
#define all(x) begin(x), end(x)

struct BIT {
    int N;
    vector<ll> bit;
    explicit BIT(int n) : N(n), bit(n+1) {}
    void update(int i, ll val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    ll query(int i) {
        ll res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

template <class T>
struct Compress {
    int sz;
    vector<T> uq;
    Compress(vector<T> &A) { add(A); go(); }
    void add(vector<T> &A) {
        uq.reserve( uq.size() + A.size() );
        uq.insert( end(uq), all(A) );
    }
    int go() {
        sort( all(uq) );
        auto fin = unique( all(uq) );
        uq.resize( fin-begin(uq) );
        return sz = uq.size();
    }
    inline  T  operator[](int i) { return uq[i]; }
    inline int operator()(int x) {
        return lower_bound( all(uq), x ) - begin(uq);
    }
};

struct MergeTree {
    int N;
    vector<ll> &A;
    vector<vector<ll>> T, P;
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            P[v] = { A[tl] };
            T[v] = { A[tl] };
        }
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            auto &L = T[v*2], &R = T[v*2+1], &W = P[v], &V = T[v];
            V.resize(tr-tl+1), W.resize(tr-tl+1);
            merge( all(L), all(R), begin(V) );
            W[0] = V[0];
            for (int i = 1; i <= tr-tl; ++i)
                W[i] = W[i-1] + V[i];
        }
    }
    ll query(ll x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    ll query(ll x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar) {
            int l = lower_bound( all(T[v]), x ) - begin(T[v]);
            int r = upper_bound( all(T[v]), x ) - begin(T[v]);
            ll a = (l > 0 ? P[v][l-1] : 0);
            ll y = x*l - a;
            ll b = P[v].back() - (r > 0 ? P[v][r-1] : 0);
            ll z = b - x*(P[v].size() - r);
            return y + z;
        }
        int mid = (tl + tr) / 2;
        ll ql = query(x, al, ar, v*2, tl, mid);
        ll qr = query(x, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<ll> &v)
        : N(n), A(v), T(4ul*n), P(4ul*n) { build(1, 0, N-1); }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    Compress<ll> cc(A);
    int c = cc.sz;

    BIT ft(c+1);
    MergeTree seg(N, A);
    auto median = [&]() {
        int l = 0, r = c;
        while (l < r) {
            int m = (l+r) >> 1;
            int x = ft.query(m);
            if (x >= (K+1)/2) r = m;
            else l = m+1;
        }
        return cc[l];
    };
    for (int i = 0; i < K; ++i) {
        int x = A[i];
        ft.update( cc(x), 1 );
    }
    ll m = median();
    cout << seg.query(m, 0, K-1) << ' ';
    for (int i = K; i < N; ++i) {
        int x = cc( A[i-K] );
        int y = cc(  A[i]  );
        ft.update(x, -1);
        ft.update(y,  1);
        m = median();
        cout << seg.query(m, i-K+1, i) << ' ';
    }

}
