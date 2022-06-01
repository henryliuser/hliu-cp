// https://codeforces.com/contest/1691/problem/D
// monostack + rmq on psum
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (n)) x++;
        return x;
    }
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    template <class T, class F>
    segtree(const std::vector<T>& v, F &init) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = init(v[i]);
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size, r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }
  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// monoid definition
const int inf = 1e18+5;
struct S { int mx=0; int mn=0; };
S init(int x)  { return S{x,x}; }
S op(S l, S r) { return S{max(l.mx, r.mx), min(l.mn, r.mn)}; }
S e()          { return S{-inf, inf}; }
using SegTree = segtree<S, op, e>;


#define top(s) s.top()
struct Monostack {
    int N;
    vector<int> &A, loop;
    Monostack(vector<int> &a)
        : A(a), N(a.size()), loop(N) { iota(all(loop),0); }
    inline void rev() { if (loop[0] == 0) reverse( all(loop) ); }
    inline void fwd() { if (loop[0] != 0) reverse( all(loop) ); }
    template <class Functor>
    inline void go(vector<int> &L, Functor cmp, bool reverse) {
        if (reverse) rev(); else fwd();
        stack<int> s;
        for (int i : loop) {
            while ( !s.empty() && cmp(A[i], A[top(s)]) ) {
                L[top(s)] = i+1;
                s.pop();
            }
            s.push(i);
        }
    }
};


string solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    Monostack ms(A);
    vector<int> nge(N, N+1), pge(N);
    ms.go(nge, greater<>(), false);
    ms.go(pge, greater<>(), true);

    vector<int> pre(N+1);
    for (int i = 0; i < N; ++i)
        pre[i+1] = pre[i] + A[i];

    SegTree seg(pre, init);
    for (int i = 1; i <= N; ++i) {
        int x = A[i-1];
        int l = pge[i-1], r = nge[i-1];
        int sl = seg.prod(l, i).mn;        // min( pre[l ... i-1] )
        int sr = seg.prod(i+1, r).mx;      // max( pre[i+1 ... r-1] )
        int ls = pre[i] - sl;              // pre[i] - sl
        int rs = sr - pre[i-1];            // sr - pre[i-1]
        if (ls > x || rs > x) return "NO";
    }
    return "YES";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}
