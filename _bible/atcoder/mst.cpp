template <class S, class Q, class R, S (*op)(const S&, const S&)>
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
    R prod(Q q, int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        R sml = 0, smr = 0;
        l += size, r += size;
        while (l < r) {
            if (l&1) sml += q(d[l++]);
            if (r&1) smr += q(d[--r]);
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
using R = int;  // query result type
struct Q {      // query type
    int x;      // query value
    inline int operator() (const S& s) {
        return end(s) - lower_bound(all(s), x);
    }
};
using MergeTree = segtree<S, Q, R, op>;
