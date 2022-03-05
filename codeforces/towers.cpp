// https://codeforces.com/problemset/problem/1637/F
// seems like always optimal to only have towers at root and leaves
// set root = max(H), each leaf starts at H[i]
// dfs from root, propagate upwards the index of the max leaf in u's subtree
// if H[u] > max in subtree, then adjust the tower at that leaf to be H[u]
// sum the towers
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
vector<ll> H;
map<int, ll> tower;
vector<vector<int>> adj;

int dfs(int u, int p) {
    ll x = H[u];
    int r = u, c = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        int m = dfs(v, u);
        if (x > tower[m]) {
            tower[m] = x;
            r = m;
        }
        if (tower[m] > c) 
            r = m,
            c = tower[m];
    }
    if (adj[u].size() == 1)  // is leaf
        tower[u] = x;
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    H.resize(N+1);
    adj.resize(N+1);
    for (int u = 1; u <= N; ++u)
        cin >> H[u];
    for (int u,v,i=1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    ll ans = 0;
    for (auto [v,x] : tower)
        ans += x;

    cout << ans << '\n';

}
