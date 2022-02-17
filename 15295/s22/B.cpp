#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> col;
vector<vector<int>> adj;

void dfs(int u, int c, int p) {
    col[u] = c;
    for (int v : adj[u])
        if (v != p)
            dfs(v, !c, u);
}

int main() {
    int N; cin >> N;
    adj.resize(N+1);
    for (int i = 0; i < N-1; ++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    col.resize(N+1);
    dfs(1, 0, -1);
    vector<vector<int>> A(2);
    for (int u = 1; u <= N; ++u)
        A[ col[u] ].push_back(u);

    map<int, ll> cnt;
    for (int x : A[1])
        cnt[x] = A[0].size();

    for (int u : A[0]) {
        for (int v : adj[u]) {
            if (cnt.count(v))
                --cnt[v];
        }
    }
    ll ans = 0;
    for (auto &p : cnt)
        ans += p.second;
    cout << ans << '\n';


}
