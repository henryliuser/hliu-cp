// floyd warshall N^3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static constexpr ll INF = 1e18;

ll u, v, c;
int N, M, Q;
vector<vector<ll>> dist;

int main() {
    cin >> N >> M >> Q;
    dist.assign(N+1, vector<ll>(N+1, INF));
    for (int i = 1; i <= N; ++i) dist[i][i] = 0;
    while (M--) {
        cin >> u >> v >> c;
        if (c < dist[u][v])
            dist[u][v] = dist[v][u] = c;
    }
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = i+1; j <= N; ++j) {
                c = dist[i][k] + dist[k][j];
                if (c < dist[i][j])
                    dist[i][j] = dist[j][i] = c;
            }

    while (Q--) {
        cin >> u >> v;
        if (dist[u][v] == INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }


}
