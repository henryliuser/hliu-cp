// https://codeforces.com/problemset/problem/999/E
// decompose into SCC's. Each scc is a node in the new graph
// for all SCC's with in-degree 0, add an edge
#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
    int N;
    int T = 0, C = 1;
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

    int operator[](int i) { return scc[i]; }

    void init(int n) {
        adj.resize(n);
        scc.resize(n);
        low.assign(n, -1);
        disc.assign(n, -1);
        curr.assign(n, 0);
    }

    Tarjan( vector<vector<int>> &g ) : adj(g) {
        N = g.size();
        init(N);
        for (int i = 1; i <= N; ++i)
            if (disc[i] == -1)
                dfs(i);
    }
};

int main() {
    int N, M, s;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> s;
    vector<vector<int>> adj(N+1);
    while (M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    Tarjan scc(adj);

    vector<int> indeg(N+1);
    for (int u = 1; u <= N; ++u)
        for (int v : adj[u])
            if (scc[u] != scc[v])
                ++indeg[ scc[v] ];

    set<int> ans;
    for (int u = 1; u <= N; ++u) {
        int c = scc[u];
        if (c == scc[s]) continue;
        if (indeg[c] != 0) continue;
        ans.insert(c);
    }

    cout << ans.size() << '\n';
}
