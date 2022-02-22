#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define setIO cin.tie(0)->sync_with_stdio(0)

int N;
vector<vector<int>> adj;
vector<int> ans, cur, goal;

void dfs(int u, int p, int odd, int even, int lvl) {
    int par = lvl % 2;
    if (par) cur[u] = (cur[u]+odd%2) % 2;
    else cur[u] = (cur[u]+even%2) % 2;

    bool ok = (cur[u] == goal[u]);
    if (!ok) {
        ans.push_back(u);
        if (par) ++odd;
        else ++even;
        cur[u] = goal[u];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, odd, even, lvl+1);
    }
}

int main() {
    setIO;
    cin >> N;
    adj.resize(N+1);
    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cur.resize(N+1), goal.resize(N+1);
    for (int i = 1; i <= N; ++i) cin >> cur[i];
    for (int i = 1; i <= N; ++i) cin >> goal[i];
    dfs(1,0,0,0,0);
    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << '\n';
}
