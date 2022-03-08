// https://codeforces.com/problemset/problem/1637/F
// key observation: if you root the tower at vertex with height max(H),
// you get this amazing property:
// there MUST be 2 subtrees of children of root with towers of height max(H)
// this means you can greedily create the towers in the subtrees later,
// propagate upwards the index of the max tower (leaf) in u's subtree
// if H[u] > max in subtree, then adjust the tower at that leaf to be H[u]
// the reason this works is because, we have ensured that there's some
// tower in u's subtree that's at least H[u], and there's certainly
// another tower in a different branch off root that's at least H[u], because
// there's one that's max(H). crazy
// finally, in the root, keep track of the max tower returned from each child
// set the top 2 of them to be max(H).
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define  all(x) (x).begin(), (x).end()
#define setIO() cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int N;
vector<ll> H;
map<int, ll> tower;
vector<vector<int>> adj;

bool gt(int a, int b) {
    return tower[a] > tower[b];
}

int dfs(int u, int p) {
    ll x = H[u];
    if (adj[u].size() == 1)  // is leaf (can be root)
        tower[u] = x;

    int r = -1;  // index of max tower in current subtree
    vector<int> T;
    for (int v : adj[u]) {
        if (v == p) continue;
        int q = dfs(v, u);
        if (p == 0) T.push_back(q);  // only track at root
        if (-1==r || tower[q] > tower[r])  // update tower
            r = q;
    }
    if (r != -1)
        tower[r] = max(tower[r], x);
    if (T.size() == 1) tower[T[0]] = x;
    else if (T.size() > 1) {
        sort(all(T), gt);
        tower[ T[0] ] = x;
        tower[ T[1] ] = x;
    }
    return r;
}

int main() {
    setIO();

    cin >> N;
    H.resize(N+1);
    adj.resize(N+1);

    int root = 1;
    for (int u = 1; u <= N; ++u) {
        cin >> H[u];
        if (H[u] > H[root])
            root = u;
    }
    for (int u,v,i=1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(root, 0);
    ll ans = 0;
    for (auto [v,x] : tower)
        ans += x;
    cout << ans << '\n';

}
