// https://codeforces.com/contest/1679/problem/D
// scc's and binary search stuff. good problem.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = pair<int, int>;

#define all(x) begin(x), end(x)

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

int N, M;
long long K;
vector<int> A;
vector<pi> edges;

bool check(int m) {
    vector<vector<int>> adj(N+1);
    for (auto [u,v] : edges)
        if (A[u] <= m && A[v] <= m)
            adj[u].push_back(v);
    Tarjan scc(adj);
    vector<int> sz(scc.C+2);
    for (int u = 1; u <= N; ++u)
        if (++sz[ scc[u] ] > 1)
            return true;
    if (K > N) return false;
    vector<int> dp(N+1, -1);
    auto dfs = [&](auto dfs, int u) {
        int &r = dp[u];
        if (r != -1) return r;
        r = 0;
        for (int v : adj[u])
            r = max(r, 1 + dfs(dfs, v));
        return r;
    };
    for (int u = 1; u <= N; ++u)
        if (dfs(dfs, u) >= K)
            return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;

    A.resize(N+1);
    edges.resize(M);
    for (int u = 1; u <= N; ++u) cin >> A[u];
    for (auto &[u,v] : edges) cin >> u >> v;

    vector<int> B = A;
    sort( all(B) );
    if (--K == 0) {
        cout << B[1];
        return 0;
    }

    int l = 1, r = N+1;
    while (l < r) {
        int m = (l+r) >> 1;
        if (check(B[m])) r = m;
        else l = m+1;
    }
    int ans = -1;
    if (l <= N) ans = B[l];
    cout << ans << '\n';
}
