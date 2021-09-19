#include <bits/stdc++.h>
using namespace std;
int N, X, Y;
int dp[301][301] = {};
//  dp[i][j] = min boxes for at least i takoyaki, j taiyaki
int main() {
    cin >> N >> X >> Y;
    dp[X][Y] = -1;
    for (int k = 1; k <= N; ++k) {
        int a, b; cin >> a >> b;
        for (int i = 1; i <= X; ++i) {
            for (int j = 1; j <= Y; ++j) {
                int a = min(a+i, X);
                int b = min(b+j, Y);
                dp[a][b] = max(dp[a][b], dp[i][j]+1);
            }
        }
    }
    for (auto& pm1 : dp) {
        for (auto pm2 : pm1) cout << pm2 << " ";
        cout << endl;
    }
    cout << dp[X][Y] << endl;

}
