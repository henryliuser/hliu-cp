// wa on last case, no idea why rip
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using tup = tuple<ll, ll, ll>;
#define f first
#define s second

int N, M;
vector<vector<pii>> graph[2];

void dijkstra(int src, int g, vector<ll> &dist) {
    ll p, u;
    priority_queue<pii> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;
        for (pii &v : graph[g][u]) {
            ll nc = v.s + dist[u];
            if (nc < dist[v.f]) {
                dist[v.f] = nc;
                pq.push({-nc, v.f});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    graph[0].resize(N+1);
    graph[1].resize(N+1);
    vector<tup> edges(M);
    ll a, b, v;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> v;
        graph[0][a].emplace_back(b, v);
        graph[1][b].emplace_back(a, v);
        edges[i] = {a,b,v};
    }
    vector<ll> dist1(N+1, LLONG_MAX), distN(N+1, LLONG_MAX);
    dijkstra(1, 0, dist1);
    dijkstra(N, 1, distN);
    ll ans = dist1[N];
    for (int i = 0; i < M; ++i) {
        tie(a,b,v) = edges[i];
        ans = min(ans, dist1[a] + v/2ll + distN[b]);
    }
    cout << ans << endl;
}
