// https://codeforces.com/contest/1695/problem/C
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;

static constexpr int MXN = 1001;

short A[MXN][MXN];
bitset<1005> dp[MXN][MXN];

string_view solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j];

    int K = N+M-1;
    if (K % 2) return "No";
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            dp[i][j] = 0;
    dp[0][1][0] = 1;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            auto L = dp[i][j-1];
            auto U = dp[i-1][j];
            if (A[i][j] == -1) dp[i][j] = L | U;
            else dp[i][j] = (L << 1) | (U << 1);
        }
    return (dp[N][M][K/2] ? "Yes" : "No");
}

signed main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
