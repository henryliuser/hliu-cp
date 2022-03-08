// https://codeforces.com/problemset/problem/1646/D
// cool question. Basically the same as AtCoder DP - independent set
// observation: no adjacent nodes can both be good
// find the max number of good nodes using tree dp
// same as "no adjacent nodes can both be painted black"
// to rebuild the tree, follow the Dp values.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
using namespace std;
using ll = long long;
using pl = array<ll, 2>;

pl dp[200005][2]{};
bool good[200005]{};
vector<vector<int>> adj;

pl cmp(pl &a, pl &b) {
    if (a == b) return a;
    if (a[0] == b[0])
        return (a[1] < b[1]) ? a : b;
    return (a[0] > b[0]) ? a : b;
}

pl dfs(int u, int c, int p) {
    pl &r = dp[u][c];
    if (r[0] != -1) return r;
    r = {0,1};
    int deg = adj[u].size();
    if (c) r[0] = 1, r[1] = deg;
    for (int v : adj[u]) {
        if (v == p) continue;
        pl x = dfs(v, 0, u);
        pl y = {-1, -1};
        if (!c) y = dfs(v, 1, u);
        pl z = cmp(x, y);
        r[0] += z[0];
        r[1] += z[1];
    }
    return r;
}

// just follow the logic from dfs
// and see if it checks out.
void build(int u, pl r, int p) {
    if (r == dp[u][0]) {
        good[u] = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            auto a = dp[v][1];
            auto b = dp[v][0];
            build(v, cmp(a,b), u);
        }
    }
    else {
        good[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            build(v, dp[v][0], u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 400010; ++i)
        dp[0][i] = {-1,-1};

    int N; cin >> N;
    adj.resize(N+1);
    for (int u,v, i=1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (N == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }
    pl a = dfs(1, 1, 0);
    pl b = dfs(1, 0, 0);
    pl c = cmp(a, b);
    cout << c[0] << ' ' << c[1] << '\n';
    build(1, c, 0);
    for (int u = 1; u <= N; ++u)
        cout << (good[u] ? adj[u].size() : 1) << ' ';
    cout << '\n';
}
