#include <bits/stdc++.h>
using namespace std;

int dp[401][401][801];
int main() {
    int ans = 0;
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> dp[i][j][0];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= K; ++k) {
                int above  = dp[i-1][j][k-1];
                int below  = dp[i][j-1][k-1];
                int diagNE = dp[i-1][j-1][k-1];
                int mx = max( {above, below, diagNE} );
                dp[i][j][k] = dp[i][j][1] + mx;
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    printf("%d\n", ans);

}
