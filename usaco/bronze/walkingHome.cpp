#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[51][51][4][2];
ll solve() {
    int N, K; cin >> N >> K;
    memset(dp, 0, sizeof dp);
    vector<string> grid(N);
    for (auto &s : grid) cin >> s;

    if (grid[0][0] == 'H') return 0;
    if (grid[1][0] == '.') dp[2][1][0][0] = 1;
    if (grid[0][1] == '.') dp[1][2][0][1] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            char ch = grid[i-1][j-1];
            if (ch == 'H') continue;
            for (int k = 0; k <= K; ++k) {
                for (int d = 0; d < 2; ++d) {
                    ll &cur = dp[i][j][k][d];
                    auto &src = (d) ? (dp[i][j-1]) : (dp[i-1][j]);
                    cur += src[k][d];
                    if (k) cur += src[k-1][!d];
                }
            }
        }

    ll res = 0;
    for (int d : {0,1})
        for (int k = 0; k <= K; ++k)
            res += dp[N][N][k][d];
    return res;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
