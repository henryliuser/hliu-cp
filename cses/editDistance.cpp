#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001] = {};
int main() {
    memset(dp, 0, sizeof dp);
    string a, b; cin >> a >> b;
    int N = a.size(), M = b.size();
    for (int i = 1; i <= N; ++i) dp[i][0] = i;
    for (int j = 1; j <= M; ++j) dp[0][j] = j;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char x = a[i-1];
            char y = b[j-1];
            int add = 1 + dp[i][j-1];
            int del = 1 + dp[i-1][j];
            int rep = (x!=y) + dp[i-1][j-1];
            dp[i][j] = min({add, del, rep});
        }
    }
    cout << dp[N][M] << endl;

}
