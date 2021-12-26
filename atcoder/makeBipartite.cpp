// https://atcoder.jp/contests/abc229/tasks/abc229_f
// dp[i][j][k] = min sum for vertices 1-i, color_1=j, color_i=k
// WA + i dont get this yet.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int MXN = 1e5+1;


ll dp[MXN][2][2];
int main() {
    int N; cin >> N;
    vector<ll> A(N+1), B(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];
    for (int i = 0; i <= N; ++i)
        for (int j : {0,1})
            dp[i][j][j]  = INF,
            dp[i][j][!j] = INF;

    dp[1][0][0] = A[1];
    dp[1][1][1] = 0;
    for (int i = 2; i <= N; ++i) {
        for (int j : {0,1})
            for (int k : {0,1})
                for (int p : {0,1}) {
                    ll &d = dp[i][j][k];
                    ll  v = dp[i-1][p][k];
                    ll  q = (!j) ? A[i] : 0;
                    ll  t = (j==p) ? B[i-1] : 0;
                    d = min(d, v+q+t);
                }
    }
    ll ans = INF;
    for (int j : {0,1})
        for (int k : {0,1}) {
            int v = (j==k) ? B[N] : 0;
            ans = min(ans, dp[N][j][k] + v);
        }

    cout << ans << "\n";
}
