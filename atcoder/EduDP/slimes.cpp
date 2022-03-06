#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    vector<ll> pre(N+1);
    for (int i = 0; i < N; ++i)
        pre[i+1] = pre[i] + A[i];
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    for (int sz = 1; sz <= N; ++sz) {
        for (int i = 0; i <= N-sz; ++i) {
            int j = i+sz-1;
            ll &res = dp[i][j];
            if (sz == 1) res = 0;
            if (sz == 2) res = A[i] + A[j];
            if (sz >= 3)
                for (int k = 0; k < sz-1; ++k) {
                    ll blob = pre[j+1] - pre[i];
                    ll x = dp[i][i+k];
                    ll y = dp[i+k+1][j];
                    res = min(res, blob+x+y);
                }
        }
    }
    cout << dp[0][N-1] << '\n';
}
