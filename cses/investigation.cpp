// dijkstra + DP, instructive.
#include <bits/stdc++.h>
using namespace std;
static constexpr int Q = 1e9+7;
using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second

int n, m;
ll p, u, v;
vector<ll> dist;
vector<int> num, maxF, minF;
vector<vector<pll>> adj;

void dijkstra(int src) {
    num[src] = 1;  // 1 route
    dist[src] = 0;
    priority_queue<pll> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;
        for (pll &e : adj[u]) {
            tie(v, p) = e;
            ll nc = dist[u] + p;
            if (nc == dist[v]) {
                // vvv represents # routes along an == shortest path
                num[v] = (num[v] + num[u]) % Q;
                minF[v] = min(minF[v], 1 + minF[u]);
                maxF[v] = max(maxF[v], 1 + maxF[u]);
            }
            if (nc < dist[v]) {
                dist[v] = nc;
                num[v] = num[u];
                minF[v] = 1 + minF[u];
                maxF[v] = 1 + maxF[u];
                pq.push({-nc, v});
            }
        }
    }
}

void init() {
    adj.resize(n+1);
    dist.assign(n+1, LLONG_MAX);
    num.assign(n+1, 0);
    minF.assign(n+1, 0);
    maxF.assign(n+1, 0);
}

int main() {
    cin >> n >> m;
    init();
    while (m--) {
        cin >> u >> v >> p;
        adj[u].emplace_back(v, p);
    }
    dijkstra(1);

    printf("%lld %d %d %d\n", dist[n], num[n], minF[n], maxF[n]);

}
