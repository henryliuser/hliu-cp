#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second

int N, M;
ll u, v, p, c;
vector<vector<pll>> adj;

int main() {
    cin >> N >> M;
    adj.resize(N+1);
    while (M--) {
        cin >> u >> v >> c;
        adj[u].emplace_back(v,c);
    }
    vector<ll> dist(N+1, LLONG_MAX);
    priority_queue<pll> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (dist[u] != -p) continue;
        for (pll v : adj[u]) {
            c = v.s - p;
            if (c < dist[v.f]) {
                dist[v.f] = c;
                pq.push({-c, v.f});
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        printf("%lld ", dist[i]);

}
