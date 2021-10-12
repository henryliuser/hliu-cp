#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MergeTree {
    ll N;
    vector<ll> &A;
    vector<vector<ll>> T;
    void build(ll v, ll tl, ll tr) {
        if (tl == tr) T[v] = {A[tl]};
        else {
            ll mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v].resize(tr-tl+1);
            auto &L = T[v*2], &R = T[v*2+1];
            merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
        }
    }
    ll query(ll x, ll L, ll R) { return query(x, L, R, 1, 0, N-1); }
    ll query(ll x, ll L, ll R, ll v, ll tl, ll tr) {
        if (L > R) return 0;
        if (L == tl && R == tr)
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
        ll mid = (tl + tr) / 2;
        ll ql = query(x, L, min(R, mid), v*2, tl, mid);
        ll qr = query(x, max(L, mid+1), R, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(ll n, vector<ll>& a)
        : N{n}, A{a}, T{4ul*n+1, vector<ll>()} { build(1, 0, n-1); }
};

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    ll N; cin >> N;
    vector<ll> hair(N), dp(N+1);
    for (ll i = 0; i < N; ++i)
        cin >> hair[i];

    MergeTree seg(N, hair);
    ll total = 0;
    for (ll i = 1; i < N; ++i) {
        ll q = seg.query(hair[i], 0, i-1);
        total += q;
        dp[hair[i]] += q;
    }
    vector<ll> ans(N);
    for (ll j = N-1; j >= 0; --j) {
        total -= dp[j];
        ans[j] = total;
    }
    for (auto a : ans)
        cout << a << endl;

}
