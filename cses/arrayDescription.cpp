// dp[i][j] = # of ways to fill up to index i, if A[i] == j
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MXN = 1e5 + 1;

int N, M;
ll dp[MXN][101] = {};
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int x; cin >> x;
        if (x != 0) {
            if (i == 1) dp[i][x] = 1;
            for (int j : {x-1, x, x+1})
                if (j > 0 && j <= M) {
                    dp[i][x] += (dp[i-1][j] % MOD);
                    dp[i][x] %= MOD;
                }
        }
        else for (int j = 1; j <= M; ++j) {
            if (i == 1) {
                dp[i][j] = 1;
                continue;
            }
            for (int k : {j-1, j, j+1})
                if (k > 0 && k <= M) {
                    dp[i][j] += (dp[i-1][k] % MOD);
                    dp[i][j] %= MOD;
                }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= M; ++i) {
        ans += (dp[N][i] % MOD);
        ans %= MOD;
    }

    cout << ans << endl;

}
