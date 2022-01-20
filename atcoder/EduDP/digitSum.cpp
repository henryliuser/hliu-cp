// https://atcoder.jp/contests/dp/tasks/dp_s
// digit dp, use t to constrain the digit options
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MXN = 10001;
const ll MOD = 1e9 + 7;

string K;
ll D; int N;
ll dp[MXN][11][101];

void add(ll &x, ll y) {
    x = (x+y) % MOD;
}

ll dfs(int i, int t, ll s) {
    if (s == 0 && i == N) return 1;
    if (i >= N) return 0;
    if (dp[i][t][s] != -1) return dp[i][t][s];

    ll res = 0;
    ll k = (t<10) ? t : (K[i]-'0');
    // if t==10, use the actual digit
    for (int j = 0; j <= k; ++j) {
        int nt = 9;  // new digit restriction
        if (t==10 && j==k)
            nt = 10;
        ll ns = (s-j+D) % D;
        ll b = dfs(i+1, nt, ns);
        add(res, b);
    }
    dp[i][t][s] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> D;
    N = K.size();

    ll ans = dfs(0, 10, 0) - 1;
    add(ans, MOD);
    cout << ans << '\n';
}
