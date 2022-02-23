// https://codeforces.com/contest/1644/problem/C
// hard to do O(N) solution for given k.
// u need range adds and stuff..
// 2 pointers doesn't work.
// doing the psum +1 -1 trick with maps/sets times out
// a lot easier to do O(N^2) for all k's
// find the best subarray at each length
// super obvious in hindsight. rip
// chmax(ans, dp[sz] + min(sz,k)*X );
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, X; cin >> N >> X;
    vector<ll> A(N), dp(N+1, -1e18);
    for (ll &x : A) cin >> x;

    for (int i = 0; i < N; ++i) {
        ll cur = 0;
        for (int j = i; j < N; ++j) {
            cur += A[j];
            int k = j-i+1;
            dp[k] = max(dp[k], cur);
        }
    }

    for (ll k = 0; k <= N; ++k) {
        ll ans = 0;
        for (ll i = 1; i <= N; ++i) {
            ll res = dp[i] + min(i,k) * X;
            ans = max(ans, res);
        }
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
