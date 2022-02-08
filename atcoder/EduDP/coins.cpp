#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dp[3000][3000] = {};
// dp[i][j] = p( getting j heads in P[:i] )
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<double> P(N);
    for (auto &x : P) cin >> x;

    for (int i = 0; i < N; ++i)
        dp[i][1] = P[i],
        dp[i][0] = 1.0 - P[i];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= i+1; ++j) {
            double h = dp[i-1][j-1] * P[i];
            double t = dp[i-1][j] * (1.0-P[i]);
            dp[i][j] = h + t;
        }
    }
    double ans = 0.0;
    int majority = (N+1)/2 + !(N%2);
    for (int j = majority; j <= N; ++j)
        ans += dp[N-1][j];
    cout << fixed << setprecision(10);
    cout << ans << '\n';

}
