// https://codeforces.com/contest/1625/problem/C
// FFS DO NOT USE LLONG_MAX
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

ll dp[505][505];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, L, K;
    cin >> N >> L >> K;
    vector<ll> D(N), A(N);
    for (ll &x : D) cin >> x;
    for (ll &x : A) cin >> x;
    D.push_back(L), A.push_back(0);
    for (int i = 0; i < 505*505; ++i)
        dp[0][i] = INF;

    dp[0][0] = 0;
    ll ans = INF;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= min(i-1, K); ++j) {
            for (int k = 0; k < i; ++k) {
                ll &r = dp[i][j];
                int q = j - (i-k-1);  // old j
                if (q < 0) continue;
                ll dx = D[i] - D[k];
                ll cur = dp[k][q] + A[k] * dx;
                r = min(r, cur);
                if (i == N) ans = min(ans, r);
            }
        }
    }
    cout << ans << '\n';
}
