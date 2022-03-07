// https://atcoder.jp/contests/dp/tasks/dp_p
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 1e9+7;

ll dp[100005][2];
vector<vector<int>> adj;

void  add(ll &a, ll b) { a = (a+b)%Q; }
void mult(ll &a, ll b) { a = (a*b)%Q; }

ll dfs(int u, int c, int p) {
    ll &r = dp[u][c];
    if (r != -1) return r;
    if (p != 0 && adj[u].size() == 1)
        return 1;

    r = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        ll x = dfs(v,0,u);
        if (!c) add( x, dfs(v,1,u) );
        mult(r, x);
    }
    return r;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    adj.resize(N+1);
    for (int u,v, i=1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = dfs(1,0,0) + dfs(1,1,0);
    cout << ans%Q << '\n';
}
