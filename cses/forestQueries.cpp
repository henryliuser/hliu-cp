#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1001][1001] = {};
int main() {
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            char ch; cin >> ch;
            dp[i][j] = (ch=='*');
            dp[i][j] += dp[i-1][j];
            dp[i][j] += dp[i][j-1];
            dp[i][j] -= dp[i-1][j-1];
        }
    }
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int rect = dp[x2][y2];
        int left = dp[x1-1][y2];
        int abov = dp[x2][y1-1];
        int smol = dp[x1-1][y1-1];
        cout << rect - left - abov + smol << "\n";
    }
}
