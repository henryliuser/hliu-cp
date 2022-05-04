#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

template <class S, S (*op)(const S&, const S&)>
struct segtree {
    int _n, size, log;
    std::vector<S> d;
    inline void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        int log = 0;
        while ((1U << log) < _n) ++log;
        size = 1 << log;
        d = std::vector<S>(2 * size, S{});
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--)
            update(i);
    }
    ll prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        ll sml = 0, smr = 0;
        l += size, r += size;
        while (l < r) {
            if (l & 1)  sml += d[l++].x;
            if (r & 1)  smr += d[--r].x;
            l >>= 1, r >>= 1;
        }
        return sml + smr;
    }
};

// monoid definition
struct S {
    int l=0,r = 1e9;
    ll x; vector<ll> v;
};
S op(const S &l, const S &r) {
    S res;
    res.l = l.l, res.r = r.r;
    int lsz = l.v.size(), rsz = r.v.size();
    res.x = l.x + r.x;
    res.v = l.v;
    if (!lsz || !rsz) return res;
    ll dx = l.v.back() - r.v[0];
    dx = max(dx, 0ll);
    res.x += dx;
    res.v[0] += dx;
    for (int i = 1; i < r.v.size(); ++i) {
        ll y = max(r.v[i], r.v[i-1]);
        ll dy = y - r.v[i];
        res.v.push_back(y);
        res.x += dy;
    }

    return res;
}
using MergeTree = segtree<S, op>;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<S> A(N);
    for (int i = 0; i < N; ++i) {
        A[i].v.resize(1);
        A[i].l = A[i].r = i;
        cin >> A[i].v[0];
        A[i].x = 0;
    }
    MergeTree seg(A);
    for (int l,r, i=0; i < Q; ++i) {
        cin >> l >> r;
        cout << seg.prod(l-1, r) << '\n';
    }
}
