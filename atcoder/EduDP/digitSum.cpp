// https://atcoder.jp/contests/dp/tasks/dp_s
// digit dp, use t to constrain the digit options
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MXN = 10001;
const ll Q = 1e9 + 7;

string K;
ll D; int N;
ll dp[MXN][2][101];

void add(ll &x, ll y) {
    ((x+=y) >= Q) ? (x-=Q) : (x < 0) ? (x+=Q) : x;
}

ll dfs(int i, bool t, ll s) {
    if (s == 0 && i == N) return 1;
    if (i >= N) return 0;
    ll &res = dp[i][t][s];
    if (res != -1) return res;

    res = 0;
    int k = (t) ? K[i]-'0' : 9;
    for (int j = 0; j <= k; ++j) {
        int nt = (t && j==k);
        ll ns = (s-j+D) % D;
        ll b = dfs(i+1, nt, ns);
        add(res, b);
    }
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> D;
    N = K.size();

    ll ans = dfs(0, 1, 0) - 1;
    add(ans, Q);
    cout << ans << '\n';
}
