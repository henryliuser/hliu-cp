#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, x, y;
vector<int>  limit, costs;
vector<vector<pair<int, int>>> graph;

vector<ll> dijkstra(int src) {
    vector<ll> dist(n, LLONG_MAX);
    vector<bool> seen(n);
    priority_queue<pair<ll, int>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        for (auto& o : graph[u]) {
            int v = o.first;
            int w = o.second;
            ll nc = dist[u] + w;
            if (nc < dist[v]) {
                dist[v] = nc;
                pq.push( {-nc, v} );
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m >> x >> y;
    limit.resize(++n);
    costs.resize(n);
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back( {v, w} );
        graph[v].push_back( {u, w} );
    }
    for (int i = 1; i < n; ++i)
        cin >> limit[i] >> costs[i];

    vector<vector<ll>> dists(n);
    for (int i = 1; i < n; ++i)
        dists[i] = dijkstra(i);
    graph.assign(n, vector<pair<int, int>>(n));
    for (int u = 1; u < n; ++u)
        for (int v = 1; v < n; ++v) {
            if (u == v) continue;
            if (dists[u][v] <= limit[u])
                graph[u].push_back( {v, costs[u]} );
        }

    ll ans = dijkstra(x)[y];
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
}
