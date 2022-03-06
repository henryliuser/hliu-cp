// https://atcoder.jp/contests/dp/tasks/dp_q
// rmq + dp
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct SegTree {
    int N;
    vector<ll> T;
    ll query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    ll query(int al, int ar, int v, int tl, int tr) {
        // al/ar: arr bounds
        if (al > ar) return 0;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        ll ql = query(al, min(ar, mid), v*2, tl, mid);
        ll qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return max(ql, qr);  // adjust
    }
    void update(int i, ll val) { update(i, val, 1, 0, N-1); }
    void update(int i, ll val, int v, int tl, int tr) {
        // i: arr index, val: new value
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = max(T[v*2], T[v*2+1]);  // adjust
        }
    }
    SegTree(int n) : N(n), T(4*n) {}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> H(N), A(N);
    for (int &x : H) cin >> x;
    for (int &x : A) cin >> x;

    ll ans = 0;
    SegTree dp(N+1);
    for (int i = 0; i < N; ++i) {
        int h = H[i];
        ll y = dp.query(0,h-1);
        ll x = A[i] + y;
        ans = max(ans, x);
        dp.update(h, x);
    }
    cout << ans << '\n';
}
