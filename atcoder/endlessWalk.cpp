// https://atcoder.jp/contests/abc245/tasks/abc245_f
// just scc then dfs
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

short dp[1<<18];
vector<int> sz;
vector<vector<int>> adj;

bool dfs(int u, Tarjan &scc) {
    short &r = dp[u];
    if (sz[ scc[u] ] > 1) return 1;
    if (r != -1) return r;
    for (int v : adj[u])
        if (dfs(v,scc))
            return r = 1;  // true
    return r = 0;  // false
}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    adj.resize(N+1);
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Tarjan scc(adj);
    sz.resize(scc.C+1);
    for (int u = 1; u <= N; ++u)
        ++sz[ scc[u] ];

    int ans = 0;
    for (int u = 1; u <= N; ++u)
        ans += dfs(u, scc);

    cout << ans << '\n';
}
