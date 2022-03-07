// http://www.usaco.org/index.php?page=viewproblem2&cpid=494
// dp[0] = inf
// for all j in m:
//    old = m ^ (1<<j)
//    a = dp[old]
//    b = str[j] - ws[old]
//    dp[m] = max(dp[m], min(a,b))
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using ar = array<ll, 3>;
const ll inf = 1e18;
const int mxp = 1048577;

ll hsm[mxp]{}, wsm[mxp]{};

int main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    ll N, H;
    cin >> N >> H;
    int p = (1 << N);
    vector<ll> dp(p, -1);
    vector<ar> cows(N);
    // {str, height, weight}
    for (auto &c : cows)
        cin >> c[0] >> c[1] >> c[2];
    for (int m = 1; m < p; ++m) {
        ll h = 0, w = 0;
        for (int j = 0; j < N; ++j)
            if (m & (1 << j))
                h += cows[j][0],
                w += cows[j][1];
        hsm[m] = h;
        wsm[m] = w;
    }

    ll ans = -1;
    dp[0] = inf;
    for (int m = 1; m < p; ++m) {
        dp[m] = -1;
        for (int j = 0; j < N; ++j) {
            ll str = cows[j][2];
            if (m & (1<<j)) {
                int old = m ^ (1<<j);
                ll w = wsm[old];
                if (dp[old] == -1) continue;
                if (w > str) continue;
                ll x = min(dp[old], str - w);
                dp[m] = max(dp[m], x);
            }
        }
        if (hsm[m] >= H)
            ans = max(ans, dp[m]);
    }
    if (ans == -1) {
        cout << "Mark is too tall\n";
        return 0;
    }
    cout << ans << '\n';
}
