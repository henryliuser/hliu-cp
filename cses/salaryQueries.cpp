// https://cses.fi/problemset/task/1144
// coordinate compress, answer offline
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define all(x) begin(x), end(x)

template <class S, S (*op)(S, S), S (*e)()> struct SegTree {
public:
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    SegTree() : SegTree(0) {}
    explicit SegTree(int n) : SegTree(std::vector<S>(n, e())) {}
    explicit SegTree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// monoid definition
using S = int;
S op(S l, S r) { return l+r; }
S e()          { return 0; }
// end ACL;

using ti = array<int, 3>;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B;
    vector<ti> qry(Q);
    for (int &x : A) {
        cin >> x;
        B.push_back(x);
    }
    for (int a,b, i=0; i < Q; ++i) {
        char t;
        cin >> t >> a >> b;
        if (t == '!')
            B.push_back(b),  // x
            qry[i] = {0,a,b};  // {k,x}
        if (t == '?')
            B.push_back(a),
            B.push_back(b),
            qry[i] = {1,a,b};
    }
    N = B.size();
    sort( all(B) );
    auto fin = unique( all(B) );
    B.resize( fin - begin(B) );
    N = B.size();
    unordered_map<int, int> compress(N);
    for (int i = 0; i < N; ++i)
        compress[ B[i] ] = i;

    SegTree<S,op,e> seg(N+5);
    for (int x : A) {
        x = compress[x];
        int y = seg.get(x);
        seg.set(x, y+1);
    }

    for (int i = 0; i < Q; ++i) {
        auto [t,a,b] = qry[i];
        if (t == 0) {
            int v = A[a-1];      // v = A[k]
            A[a-1] = b;          // A[k] = x
            v = compress[v];     // compress[v]
            b = compress[b];     // compress[x]
            int y = seg.get(v);  // seg[k]
            int z = seg.get(b);  // seg[x]
            seg.set(v, y-1);     // --cnt[ A[k] ]
            seg.set(b, z+1);     // ++cnt[x]
        }
        if (t == 1) {
            a = compress[a], b = compress[b];
            cout << seg.prod(a, b+1) << '\n';
        }

    }
}
