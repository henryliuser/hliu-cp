// https://atcoder.jp/contests/abc250/tasks/abc250_g
// very instructive: start in a minimal state, such that
// all operations push the answer in the same direction.
// instead of starting at none and deciding between sell and buy
// which seems pretty arbitrary, start everything at buy
// and gradually improve the answer, observing the limitations
// and effects on the prefix sum.
//
// let p[i] = {-1: sell, 0: none, 1: buy}, and p = [1] * N initially
// let `pre` be a lazy segment tree representing the dynamic prefix sum of p
// the prefix sum of p may never be negative (because u can't sell if u don't have any)
// the score of any configuration of p is -(p dot A).
// the initial score `cur` is -sum(A).
// each round, we try to greedily improve the score
// consider the max, rightmost A[i] that hasn't been processed yet.
//
// we can convert it to a sell iff the suffix min of the (prefix sum of p) `pre.rmq(i,N)` is >= 2
// if we change it from buy to sell:
//     p[i] -= 2
//     pre[i...N] -= 2
//     cur += 2 * A[i]
//
// else, we can convert it to none iff the suffix min >= 1
// if change from buy to none:
//     p[i] -= 1
//     pre[i...N] -= 1
//     cur += A[i]
//
// we convert as many as we can, then the remaining cur is the answer.
// complexity is O(N log N)
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll INF = 1e18+5;
#define all(x)   begin(x), end(x)
#define rall(x)  x.rbegin(), x.rend()

template <class S,
        S (*op)(S, S),
        S (*e)(),
        class F,
        S (*mapping)(F, S),
        F (*composition)(F, F),
        F (*id)()>
struct LazySegTree {
public:
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    LazySegTree() : LazySegTree(0) {}
    explicit LazySegTree(int n) : LazySegTree(std::vector<S>(n, e())) {}
    explicit LazySegTree(int n, S x) : LazySegTree(std::vector<S>(n, x)) {}
    explicit LazySegTree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

// lazy seg definition
using S = ll;
using F = ll;
S op(S l, S r)         { return min(l, r); }
S e()                  { return INF; }
S mapping(F l, S r)    { return r+l; }
F compose(F l, F r)    { return l+r; }
F id()                 { return 0;   }
using LazySeg = LazySegTree<S, op, e, F, mapping, compose, id>;
using pi = pair<ll, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll cur = 0;
    int N; cin >> N;
    vector<pi> A(N);
    vector<ll> p(N);
    iota( all(p), 1 );
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
        cur -= A[i].first;
    }

    LazySeg pre(p);
    sort( rall(A) );
    for (auto [x,i] : A) {
        ll mn = pre.prod(i, N);
        ll m = min(mn, 2ll);
        cur += m * x;
        pre.apply(i, N, -m);
    }
    cout << cur << '\n';
}
