#include <bits/stdc++.h>
using namespace std;

int a, b;
const int INF = 1e9+1;
int dp[501][501] = {};
int main() {
    cin >> a >> b;
    memset(dp, INF, sizeof dp);  // so this is actually UB lol.
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            int &v = dp[i][j];
            if (i == j) {  // already a square
                v = 0;
                continue;
            }
            for (int k = 1; k <= i; ++k)
                v = min(v, 1 + dp[k][j] + dp[i-k][j]);
            for (int k = 1; k <= j; ++k)
                v = min(v, 1 + dp[i][k] + dp[i][j-k]);
        }
    }
    cout << dp[a][b] << endl;
}
