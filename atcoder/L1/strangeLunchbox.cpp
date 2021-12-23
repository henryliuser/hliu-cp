#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int SZ = 301*301*301;

int N, X, Y;
int dp[301][301][301];
// dp[i][j][k] = min # of boxes to achieve j takoyaki, k taiyaki,
// using only first i items
// push forward recurrence : if we did it backwards, we'd need to store
// dp[301][601][601] for case like: N=2, X=300, Y=300 / (299,299), (299,299)
// which still runs in time but is much slower

int main() {
    cin >> N >> X >> Y;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    for (int i = 0; i < SZ; ++i)
        dp[0][0][i] = INF;  // stupid and maybe UB but gets AC on atcoder

    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int x = A[i], y = B[i];
        for (int a = 0; a < 301; ++a) {
            for (int b = 0; b < 301; ++b) {
                int q = dp[i][a][b];
                int j = min(a+x, X), k = min(b+y, Y);
                int &p = dp[i+1][j][k];
                int &d = dp[i+1][a][b];
                p = min(p, q+1);
                d = min(d, q);
            }
        }
    }
    int ans = dp[N][X][Y];
    if (ans == INF) ans = -1;
    cout << ans << "\n";

}
