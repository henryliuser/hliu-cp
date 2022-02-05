// http://www.usaco.org/index.php?page=viewproblem2&cpid=574
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 5e6+5;

bool dp[2][MXN];

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    memset(dp, 0, sizeof dp);
}

int main() {
    init();
    int ans = 0;
    int T, A, B; cin >> T >> A >> B;

    dp[0][0] = 1;
    for (int i = 0; i <= T; ++i) {
        if (dp[0][i]) {
            ans = max(ans, i);
            if (i+A <= T) dp[0][i+A] = 1;
            if (i+B <= T) dp[0][i+B] = 1;
            dp[1][i/2] = 1;
        }
    }
    for (int i = 0; i <= T; ++i) {
        if (dp[1][i]) {
            ans = max(ans, i);
            if (i+A <= T) dp[1][i+A] = 1;
            if (i+B <= T) dp[1][i+B] = 1;
        }
    }
    cout << ans << '\n';
}
