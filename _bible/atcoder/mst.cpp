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
    int prod(int x, int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        int sml = 0, smr = 0;
        l += size, r += size;
        while (l < r) {
            if (l & 1) {
                auto &s = d[l++];
                sml += end(s) - lower_bound(all(s), x);
            }
            if (r & 1) {
                auto &s = d[--r];
                smr += end(s) - lower_bound(all(s), x);
            }
            l >>= 1, r >>= 1;
        }
        return sml + smr;
    }
};

// monoid definition
using S = vector<int>;
S op(const S &l, const S &r) {
    S res;
    res.resize(l.size() + r.size());
    merge(all(l), all(r), begin(res));
    return res;
}
using MergeTree = segtree<S, op>;
