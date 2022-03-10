// https://codeforces.com/problemset/problem/1418/C
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
vector<ll> A;
vector<vector<ll>> dp;

ll dfs(int i, int p) {
    ll &res = dp[i][p];
    if (i >= N) return 0;
    if (res != -1) return res;

    if (p == 1) {
        ll a = dfs(i+1, !p);
        ll b = dfs(i+2, !p);
        res = min(a,b);
    }
    if (p == 0) {
        ll a = A[i] + dfs(i+1, !p);
        ll b = 1e18;
        if (i+1 < N)
            b = A[i] + A[i+1] + dfs(i+2, !p);
        res = min(a,b);
    }
    return res;
}

ll solve() {
    cin >> N;
    A.resize(N);
    for (ll &x : A) cin >> x;
    dp.assign(N,vector<ll>(2,-1));
    return dfs(0,0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
