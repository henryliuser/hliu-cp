// https://codeforces.com/problemset/problem/1635/F
// solve the question for whole array in O(N) first
// monostack:
// W: 100  99   1
// x:  1   99  100
// i:  0   1    2
//
// no need to consider pair (0,2) because (1,2) clearly better
// thus, define L, R such that
// L[i] = max j such that j<i && w[j] <= w[i]
// R[i] = min j such that j>i && w[j] <= w[i]
// now we taken the min across 2N points (L[i], i), (i, R[i])
//
// for range query, we take the minimum pair that's fully contained in [l, r]
// for all l,r there is guaranteed to be some pair that is fully contained.
// consider any 2 adjacent points (i,j): if w[j] <= w[i] then (i,j) is a pair
// if w[j] > w[i], then (j,i) is a pair.
//
// key: although (L[i], i) and (i, R[i]) may not be the best pairs for i
// in the query range [l,r], it is guaranteed the the best will exist
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#define  all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
const ll INF = 1e18;

struct SegTree {
    int N;
    vector<int> T;
    int query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    int query(int al, int ar, int v, int tl, int tr) {
        // al/ar: arr bounds
        if (al > ar) return INF;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(al, min(ar, mid), v*2, tl, mid);
        int qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return min(ql, qr);  // adjust this
    }
    void update(int i, int val) { update(i, val, 1, 0, N-1); }
    void update(int i, int val, int v, int tl, int tr) {
        // i: arr index, val: new value
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = min(T[v*2], T[v*2+1]);  // adjust this
        }

    }
    SegTree(int n) : N(n), T(4*n) {}
};

template<class vec, class mp>
void mono(vec &idx, mp &m, vec &W) {
    stack<ll> s;
    for (ll i : idx) {
        ll j = s.top();
        while (s.size() && W[i] <= W[j]) {
            m[max(i,j)].push_back(min(i,j));
            s.pop();
            j = s.top();
        }
        s.push(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> X(N), W(N), ans(Q);
    map<int, vector<pl>> occ;
    map<int, vector<int>> pairs;
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> W[i];
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        occ[r].push_back( {l,i} );
    }
    for (auto &[r,v] : occ)
        sort( rall(v) );

    vector<ll> nxt(N), prv(N);
    iota(all(nxt), 0), iota(rall(prv), 0);
    mono(nxt, pairs, W), mono(prv, pairs, W);

    auto ws = [&](int i, int j) {
        ll dx = abs(X[i] - X[j]);
        ll sw = W[i] + W[j];
        return dx*sw;
    };

    SegTree seg(N+1);
    fill( all(seg.T), INF );
    for (int r = 1; r <= N; ++r) {
        for (int l : pairs[r])
            seg.update(l, ws(l,r));
        for (auto [l,i] : occ[r])
            ans[i] = seg.query(l,r);
    }
    for (int q = 0; q < Q; ++q)
        cout << ans[q] << '\n';


}
