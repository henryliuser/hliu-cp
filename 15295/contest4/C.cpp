#include <bits/stdc++.h>
using namespace std;
int N;
vector<bool> seen;
vector<int> sizes, dp;
vector<vector<int>> graph;

int dfs(int u) {
    // cout << "u: " << u << endl;
    seen[u] = true;
    int sz = 1;
    for (int v : graph[u])
        if (!seen[v]) sz += dfs(v);
    sizes[u] = sz;
    return sz;
}

int cuts(int u) {
    // cout << "cuts u: " << u << endl;
    seen[u] = true;
    if (sizes[u] % 2 == 1) return 0;
    if (dp[u] != -1) return dp[u];
    int c = 0;
    for (int v : graph[u]) {
        if (sizes[v] % 2 == 1) continue;
        if (!seen[v]) c += 1 + cuts(v);
    }
    dp[u] = c;
    return c;
}

int main() {
    cin >> N;
    ++N;
    seen.resize(N);
    sizes.resize(N);
    graph.resize(N);
    dp.assign(N,-1);
    for (int i = 0; i < N-2; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << "GRAPH\n";
    int pc = 0;
    for (auto& pm1 : graph) {
        cout << pc++ << ": ";
        for (auto pm2 : pm1) cout << pm2 << " ";
        cout << endl;
    }
    cout << "GRAPH\n";
    dfs(1);
    for (auto pm : sizes) cout << pm << " "; cout << endl;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        seen.assign(N, false);
        ans = max(ans, cuts(i));
    }

    cout << ((sizes[1] % 2) ? -1 : ans) << endl;
}
