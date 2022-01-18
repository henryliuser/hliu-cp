#include <bits/stdc++.h>
using namespace std;
using edge = array<int, 2>;

// int c = 0;
int cyc[] = {2, 3};
void dfs(int u, int p, int c,
         vector<vector<edge>> &adj,
         vector<int> &ans)
{
    for (edge &v : adj[u]) {
        if (v[0] == p) continue;
        ans[ v[1] ] = cyc[c];
        c = (c+1) % 2;
        dfs(v[0], u, c, adj, ans);
    }
}

vector<int> solve() {
    int N; cin >> N;
    vector<edge> E(N-1);
    vector<int> ans(N-1);
    vector<vector<edge>> adj(N+1);
    for (int i = 0; i < N-1; ++i) {
        edge &e = E[i];
        cin >> e[0] >> e[1];
        adj[e[0]].push_back({e[1],i});
        adj[e[1]].push_back({e[0],i});
    }
    for (auto &v : adj)
        if (v.size() >= 3) return {};

    dfs(1, 1, 0, adj, ans);
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        auto s = solve();
        if (s.empty()) cout << -1;
        else for (int x : s)
            cout << x << " ";
        cout << '\n';
    }
}
