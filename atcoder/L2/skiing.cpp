// https://atcoder.jp/contests/abc237/tasks/abc237_e
// think about the POTENTIAL of nodes
// if i start at H[1] and end at H[u],
// the absolute max i could have gained is H[1] - H[u].
// but the intermediate path has some cost as well. That's what we're
// dijkstra'ing on.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
const ll INF = 1e18+5;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> H(N+1);
    vector<vector<pll>> adj(N+1);
    for (int u = 1; u <= N; ++u) cin >> H[u];
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        if (H[u] > H[v]) swap(u,v);
        adj[u].push_back( {v, H[v]-H[u]} );
        adj[v].push_back( {u, 0} );
    }
    vector<ll> dist(N+1, INF);
    dist[1] = 0;
    priority_queue<pll> pq;
    pq.push( {0, 1} );
    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;
        for (auto [v,c] : adj[u]) {
            ll d = c - p;
            if (d < dist[v]) {
                dist[v] = d;
                pq.push( {-d, v} );
            }
        }
    }
    ll ans = 0;
    for (int u = 2; u <= N; ++u) {
        ll dh = H[1] - H[u];
        ans = max(ans, dh - dist[u]);
    }
    cout << ans << '\n';
}
