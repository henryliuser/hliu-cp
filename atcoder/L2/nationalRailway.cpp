#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXN = 1005;
const ll INF = 1e9+5;

int H, W;
ll C, dp[MXN][MXN];

int main() {
    fill((ll*)dp, (ll*)dp+MXN*MXN, INF);
    cin.tie(0)->sync_with_stdio(0);

    ll ans = INF;
    cin >> H >> W >> C;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j) {
            ll &r = dp[i][j];
            cin >> r;
            ans = min( {ans, dp[i-1][j] + r, dp[i][j-1] + r} );
            r = min( {r, dp[i-1][j] + C, dp[i][j-1] + C} );
        }
    cout << ans << '\n';
}
