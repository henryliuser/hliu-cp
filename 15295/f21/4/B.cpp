#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int L = n - m + 1;
    vector<ll> A(n), pre(n+1), S(L);
    vector<vector<ll>> dp(L+1, vector<ll>(k+1));
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i-1] + A[i-1];
    for (int i = 0; i < L; ++i)
        S[i] = pre[i+m] - pre[i];;

    for (int j = 1; j <= k; ++j)
        for (int i = 1; i <= L; ++i) {
            dp[i][j] = max(dp[i-1][j], S[i-1]);
            if (i < m) continue;
            dp[i][j] = max(dp[i][j], S[i-1] + dp[i-m][j-1]);
        }

    cout << dp[L][k] << endl;

}
