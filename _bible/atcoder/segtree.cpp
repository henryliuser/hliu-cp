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
const int inf = 1e9+5;
struct S { int mx=0; int mn=0; };
S init(int x)  { return S{x,x}; }
S op(S l, S r) { return S{max(l.mx, r.mx), min(l.mn, r.mn)}; }
S e()          { return S{-inf, inf}; }
using SegTree = segtree<S, op, e>;
