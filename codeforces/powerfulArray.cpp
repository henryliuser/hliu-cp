// https://codeforces.com/problemset/problem/86/D
// just mo's
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
using namespace std;
using ll = long long;
const int MXN = 1e6+5;

#define int ll
#define all(x) (x).begin(), (x).end()

struct Mo {
    // static const int B = 500;   // block size
    static const int K = 21;    // hilbert order power, 2^K

    int L=1, R=0;
    vector<ll> &A;
    ll cnt[MXN] = {};
    ll cur = 0;
    inline void del(ll x) {
        cur += (1ll - 2ll*cnt[x]--) * x;  // doing it manually is 2x slower
    }
    inline void add(ll x) {
        cur += (1ll + 2ll*cnt[x]++) * x;
    }
    inline const ll get() {
        return cur;
    }
    static ll hilbert(int x, int y, int pow, int rotate) {
        if (pow == 0) return 0;
        int hpow = 1 << (pow-1);
        int seg = (x<hpow) ? ( (y<hpow)?0:3 ) : ( (y<hpow)?1:2 );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        ll subSquareSize = 1ll << (2*pow - 2);
        ll ans = seg * subSquareSize;
        ll add = hilbert(nx, ny, pow-1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }
    struct Query {
        ll ord;
        int l, r, i;
        void calc() { ord = hilbert(l, r, K, 0); }
        friend bool operator<(const Query& a, const Query& b) {
            return a.ord < b.ord;
        }
    };
    template <class T>
    void process(vector<Query> &qry, vector<T> &ans) {
        sort( all(qry) );
        for (Query &q : qry) {
            while (L > q.l) add( A[--L] );
            while (R < q.r) add( A[++R] );
            while (R > q.r) del( A[R--] );
            while (L < q.l) del( A[L++] );
            ans[q.i] = get();
        }
    }
    Mo(vector<ll> &a) : A(a) { }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N >> T;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    vector<Mo::Query> qry(T);
    for (int i = 0; i < T; ++i) {
        auto &q = qry[i];
        cin >> q.l >> q.r;
        q.i = i;
        q.calc();
    }

    Mo mo(A);
    vector<ll> ans(T);
    mo.process(qry, ans);
    for (ll x : ans)
        cout << x << '\n';
}
