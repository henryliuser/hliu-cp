// https://leetcode.com/contest/biweekly-contest-79/problems/booking-concert-tickets-in-groups/
// nice easy application of seg tree
using ll = long long;
using pi = pair<int, int>;

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
const int inf = 1e9+5;
struct S { int mx; ll s; };
S op(S l, S r) { return S{ max(l.mx,r.mx), l.s+r.s }; }
S e()          { return S{ -inf,0 }; }
using SegTree = segtree<S, op, e>;


class BookMyShow {
public:
    int n, m;
    int j = 0;  // full index
    vector<S> B;
    vector<int> A;
    SegTree *st;

    BookMyShow(int n, int m) : n(n), m(m) {
        A.assign(n, m);
        B.assign(n+1, S{m,m});
        st = new SegTree(B);
    }

    vector<int> gather(int k, int maxRow) {
        int l = 0, r = maxRow+1;
        while (l < r) {
            int m = (l+r) >> 1;
            int mn = st->prod(0, m+1).mx;
            if (mn >= k) r = m;
            else l = m+1;
        }
        if (l > maxRow) return {};
        r = m - A[l];
        A[l] -= k;
        st->set( l, S{A[l], A[l]} );
        return {l,r};
    }

    bool scatter(int k, int maxRow) {
        ll s = st->prod(0,maxRow+1).s;
        if (s < k) return false;
        while (j < n && k) {
            int dx = min(k, A[j]);
            A[j] -= dx;
            st->set( j, S{A[j], A[j]} );
            k -= dx;
            if (!A[j]) ++j;
        }
        return true;
    }
};
