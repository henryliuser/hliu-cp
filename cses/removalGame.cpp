// https://cses.fi/problemset/task/1097
// p0 maximize X-Y, p1 minimize X-Y
// makes recurrence easier.
// at the end we have sum = X+Y
// sum + X-Y = 2X, div 2 and u have answer
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll INF = 1e18;

int N;
vector<ll> A;
ll dp[5001][5001][2];

ll dfs(int i, int j, int p) {
    ll &res = dp[i][j][p];
    if (res != INF) return res;
    ll m = (p) ? -1 : 1;
    if (i == j) return m*A[i];
    ll l = m*A[i] + dfs(i+1, j, !p);
    ll r = m*A[j] + dfs(i, j-1, !p);
    if (p == 0) res = max(l, r);
    if (p == 1) res = min(l, r);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 50020002; ++i)
        dp[0][0][i] = INF;

    cin >> N;
    ll sum = 0;
    A.resize(N);
    for (ll &x : A) {
        cin >> x;
        sum += x;
    }
    ll res = dfs(0, N-1, 0);
    ll ans = (sum+res) / 2;
    cout << ans << '\n';

}
