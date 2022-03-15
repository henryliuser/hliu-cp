// https://codeforces.com/contest/840/problem/D
// randomized algorithm
// 90 iterations, pick the minimum. since it's a frequency thing
// probability is tiny
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = pair<int,int>;
const int MXN = 3e5+5;
const int INF = 1e9+5;
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Mo {
    using ll = long long;
    // static const int B = 316;
    static const int K = 21;    // hilbert order power, 2^K

    int L=1, R=0;
    int cnt[MXN] = {};
    vector<int> &A;

    inline void del(int i) {
        --cnt[ A[i] ];
    }
    inline void add(int i) {
        ++cnt[ A[i] ];
    }
    inline const int get(int k) {
        int dx = R-L+1;
        int v = dx/k;
        int x = INF;
        for (int i = 0; i < 90; ++i) {
            int r = rng() % dx;
            if (cnt[A[L+r]] > v)
                x = min(x, A[L+r]);
        }
        return (x != INF) ? x : -1;
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
        int l, r, k, i;
        void calc() { ord = hilbert(l, r, K, 0); }
        friend bool operator<(const Query& a, const Query& b) {
            return a.ord < b.ord;
        }
    };
    template <class VI, class VO>
    Mo(VI &a, vector<Query> &qry, VO &ans) : A(a) {
        for (Query &q : qry) {
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (R > q.r) del(R--);
            while (L < q.l) del(L++);
            ans[q.i] = get(q.k);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    vector<int> ans(Q);
    vector<Mo::Query> qry(Q);
    for (int i = 0; i < Q; ++i) {
        auto &q = qry[i];
        cin >> q.l >> q.r >> q.k;
        q.i = i;
        q.calc();
    }
    sort( all(qry) );
    Mo mo(A, qry, ans);
    for (int x : ans)
        cout << x << '\n';
}
