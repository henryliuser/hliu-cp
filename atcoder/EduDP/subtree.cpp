// stop bagholding, < 20 days.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N, M;
vector<ll> ans;
ll dp[100005][3]{};
vector<vector<int>> adj;

void mul(ll &x, ll y) { (x*=y) %= M; }
void add(ll &x, ll y) { (x+=y) %= M; }

ll dfsDown(int u, int p) {
    if (p && size(adj[u]) == 1) return 2;
    if (down[u] != -1) return down[u];

    down[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        mul(down[u], dfs(v,u));
    }
    return down[u] += 1;
}

ll dfsUp(int u, int p) {

}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    adj.resize(N+1);
    ans.resize(N+1);
    for (int u,v, i=1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    dfs(1, 2, 0);

    for (int u = 1; u <= N; ++u)
        cout << ans[u] << '\n';
}
