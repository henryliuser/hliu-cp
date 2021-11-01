#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
int dp[5001][5001] = {};
int main() {
    string a, b;
    cin >> a >> b;
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;
    int N = a.size(), M = b.size();
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            char x = a[i-1];
            char y = b[j-1];
            int &v = dp[i][j];
            if (j) v = min(v, 1 + dp[i][j-1]);            // add
            if (i) v = min(v, 1 + dp[i-1][j]);            // delete
            if (i&&j) v = min(v, (x!=y) + dp[i-1][j-1]);  // replace
        }
    }
    cout << dp[N][M] << endl;

}
