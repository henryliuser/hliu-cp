// https://cses.fi/problemset/task/1686/
// scc + dp
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct Tarjan {
    int N;
    int T = 0, C = 0;
    vector<int> path;
    vector<bool> curr;
    vector<int> disc, low, scc;
    vector<vector<int>> &adj;

    void dfs(int u) {
        curr[u] = true;
        int i = path.size();
        path.push_back(u);
        disc[u] = low[u] = T++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {  // if not visited
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (curr[v])  // genius part
                low[u] = min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {  // found an SCC
            int id = C++;
            for (int j = i; j < path.size(); ++j) {
                scc[path[j]] = id;
                curr[path[j]] = false;
            }
            path.resize(i);
        }
    }

    inline int operator[](int i) { return scc[i]; }

    Tarjan( vector<vector<int>> &g )
            : N(g.size()), adj(g), scc(N), low(N,-1), disc(N,-1), curr(N) {
        for (int i = 1; i < N; ++i)  // adjust me maybe
            if (disc[i] == -1)
                dfs(i);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<ll> A(N+1), dp(N+1,-1);
    vector<vector<int>> adj(N+1);
    for (int u = 1; u <= N; ++u) cin >> A[u];
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Tarjan scc(adj);
    vector<ll> sum(scc.C+1);
    vector<vector<int>> meta(scc.C+1);
    for (int u = 1; u <= N; ++u) {
        int z = scc[u];
        sum[z] += A[u];
        for (int v : adj[u])
            if (z != scc[v])
                meta[z].push_back(scc[v]);
    }
    auto dfs = [&](auto dfs, int u) {
        ll &r = dp[u];
        if (r != -1) return r;
        ll x = r = sum[u];
        for (int v : meta[u])
            r = max(r, x + dfs(dfs, v));
        return r;
    };
    ll ans = 0;
    for (int z = 0; z <= scc.C; ++z)
        ans = max(ans, dfs(dfs, z));
    cout << ans << '\n';
}
