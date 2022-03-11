// https://atcoder.jp/contests/abc242/tasks/abc242_g
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = pair<int,int>;
const int MXN = 100005;

struct SegTree {
    int N;
    vector<ll> T;
    ll query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    ll query(int al, int ar, int v, int tl, int tr) {
        if (al > ar) return 0;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        ll ql = query(al, min(ar, mid), v*2, tl, mid);
        ll qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    void update(int i, ll val) { update(i, val, 1, 0, N-1); }
    void update(int i, ll val, int v, int tl, int tr) {
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1]);
        }
    }
    SegTree(int n) : N(n), T(4*n) {}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    map<int, int> last;
    vector<int> occ[MXN]
    vector<pi> qry[MXN];

    cin >> N;
    vector<int> prv(N,-1);
    for (int x, i=0; i < N; ++i) {
        cin >> x;
        if (last.count(x))
            occ[i].push_back(last[x]),
            prv[i] = last[x];
        last[x] = i;
    }
    cin >> Q;
    for (int l,r, q=0; i < Q; ++q) {
        cin >> l >> r;
        qry[r].push_back( {l,q} );
    }

    SegTree seg(N+1);
    vector<int> ans(Q);
    for (int i = 0; i < N; ++i) {
        for (int l : occ[i]) {
            seg.update(l, 1);
            if (prv[l] != -1)
                seg.update(prv[l], -1);
        }
        for (auto [l,q] : qry[i])
            ans[q] = seg.query(l, i) - 1;
    }
    for (int q = 0; q < Q; ++q)
        cout << ans[q] << '\n';
}
