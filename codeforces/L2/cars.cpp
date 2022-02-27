// https://codeforces.com/contest/1635/problem/E
// build a graph with cars as nodes and restrictions as edges
// (track the types for each edge)
// if between 2 nodes are 2 different edges, obviously NO
// dfs to check bipartite-ness of graph
// if not bipartite then NO
// reasoning: if 2 cars destined then they have opposite direction
// if 2 cars irrelevant, they also have opposite direction
// if graph is not bipartite, then some of these opposite
// restrictions have been violated.
// After arbitrarily assigning some direction to the first,
// we have some position restrictions based on L's and R's
// Top sorting these positional restrictions forms a solution
// update: apparently sometimes u can fail to topsort it, if so print NO
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define tl(x) array<ll, x>

int N, M;
int t, u, v;
vector<int> indeg, dir;
vector<vector<int>> adj, adj2;

void dfs(int u, int d) {
    dir[u] = d;
    for (int v : adj[u]) {
        if (dir[v] == d) throw -1;
        if (dir[v] == -1) dfs(v, !d);
    }
}

vector<int> topSort() {
    queue<int> q;
    vector<int> ans(N+1);
    for (int u = 1; u <= N; ++u)
        if (indeg[u] == 0)
            q.push(u);

    int x = 0;
    while (!q.empty()) {
        int u = q.front();
        ans[u] = x++;
        for (int v : adj2[u])
            if (--indeg[v] == 0)
                q.push(v);
        q.pop();
    }
    if (x != N) throw -1;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    adj.resize(N+1);
    dir.assign(N+1, -1);
    vector<tl(3)> edges(M);
    for (int e = 0; e < M; ++e) {
        cin >> t >> u >> v;
        edges[e] = {t,u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    try {
        for (int u = 1; u <= N; ++u)
            if (dir[u] == -1)
                dfs(u, 0);  // 0:left, 1:right

        int ord[2];
        adj2.resize(N+1);
        indeg.resize(N+1);
        for (auto &e : edges) {
            ord[ dir[e[1]] ] = e[1];
            ord[ dir[e[2]] ] = e[2];
            if (e[0] == 2) swap(ord[0], ord[1]);
            adj2[ord[0]].push_back(ord[1]);
            ++indeg[ord[1]];
        }
        auto ans = topSort();
        cout << "YES" << '\n';
        for (int u = 1; u <= N; ++u)
            cout << (dir[u] ? "R " : "L ")
                 <<  ans[u] << '\n';
    }
    catch (...) { cout << "NO\n"; }

}
