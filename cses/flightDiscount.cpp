#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using tup = tuple<ll, ll, ll>;
using pll = pair<ll, ll>;
#define f first
#define s second

int N, M;
vector<vector<pll>> graph[2];

void dijkstra(int src, int g, vector<ll> &dist) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    ll p, u;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (p != dist[u]) continue;
        for (pll &v : graph[g][u]) {
            ll nc = v.s + dist[u];
            if (nc < dist[v.f]) {
                dist[v.f] = nc;
                pq.push({nc, v.f});
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
        ans = min(ans, dist1[a] + v/2ull + distN[b]);
    }
    cout << ans << endl;
}
