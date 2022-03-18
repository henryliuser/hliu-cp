// https://atcoder.jp/contests/abc242/tasks/abc242_g
// just use mo's and maintain the stuff using umap/freq
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
const int MXN = 1e5+2;

#define all(x) (x).begin(), (x).end()

struct Mo {
    using ll = long long;
    static const int B = 316;
    static const int K = 21;    // hilbert order power, 2^K

    int L=1, R=0;
    int cnt[MXN] = {};
    vector<int> &A;
    int cur = 0;
    inline void del(int i) {
        if (cnt[ A[i] ]-- % 2 == 0)
            --cur;
    }
    inline void add(int i) {
        if (++cnt[ A[i] ] % 2 == 0)
            ++cur;
    }
    inline const int get() {
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
        Query(int l, int r, int i) : l(l), r(r), i(i) { calc(); }
        friend bool operator<(const Query& a, const Query& b) {
            return a.ord < b.ord;
        }
    };
    template <class T>
    void process(vector<Query> &qry, vector<T> &ans) {
        for (Query &q : qry) {
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (R > q.r) del(R--);
            while (L < q.l) del(L++);
            ans[q.i] = get();
        }
    }
    Mo(vector<int> &a) : A(a) {}
};

int main() {
    int N; cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    Mo mo(A);
    int Q; cin >> Q;
    vector<Mo::Query> qry;
    for (int l,r, i=0; i < Q; ++i) {
        cin >> l >> r;
        Mo::Query q(l,r,i);
        qry.push_back(q);
    }
    sort( all(qry) );
    vector<int> ans(Q);
    mo.process(qry, ans);
    for (int x : ans)
        cout << x << '\n';
}
