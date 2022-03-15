// https://atcoder.jp/contests/abc243/tasks/abc243_e
// as long as is there is any alternative path <= c,
// you can definitely remove it
// you can do all sources dijkstra or floyd warshall then compare
// i still dont quite get the intuition for why u can consider
// the deletion of each edge independently
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll inf = 1e18+5;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<vector<ll>> dist(N+1, vector<ll>(N+1, inf));
    vector<array<ll,3>> edges(M);
    for (ll u,v,c, i=0; i < M; ++i) {
        cin >> u >> v >> c;
        dist[u][v] = dist[v][u] = min(dist[u][v], c);
        edges[i] = {u,v,c};
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = i+1; j <= N; ++j) {
                ll c = dist[i][k] + dist[k][j];
                if (c < dist[i][j])
                    dist[i][j] = dist[j][i] = c;
            }

    int ans = 0;
    for (auto [u,v,c] : edges) {
        for (int i = 1; i <= N; ++i) {
            if (i == u || i == v) continue;
            if (dist[u][i] + dist[i][v] <= c)
                goto ok;
        }
        continue;
        ok: ++ans;
    }

    cout << ans << '\n';
}
