#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

#define int int64_t
#define all(x) begin(x), end(x)

namespace HL {

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

} // ns LIB

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<ll> X(N+1), C(N+1);
    vector<vector<int>> adj(N+1);
    for (int u = 1; u <= N; ++u) {
        cin >> X[u];
        adj[u].push_back( X[u] );
    }
    for (int u = 1; u <= N; ++u) cin >> C[u];

    HL::Tarjan scc(adj);
    vector<vector<int>> comp(scc.C);
    for (int u = 1; u <= N; ++u)
        comp[ scc[u] ].push_back(u);

    ll ans = 0;
    for (int c = 0; c < scc.C; ++c)
        if (comp[c].size() > 1) {
            ll res = 1e9+5;
            for (int u : comp[c])
                res = min(res, C[u]);
            ans += res;
        }

    cout << ans << '\n';

}
