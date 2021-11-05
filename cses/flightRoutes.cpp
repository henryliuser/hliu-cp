// pq at each node Dijkstra, instructive!
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+1;
using ll = long long;
using pll = pair<ll, ll>;

int n, m, k;
ll u, p, v, c;
priority_queue<ll> bests[MXN];
vector<vector<pll>> adj;

void dijkstra(int src) {
    bests[src].push(0);
    priority_queue<pll> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (-p > bests[u].top()) continue;
        for (pll &e : adj[u]) {
            tie(v, c) = e;
            ll nc = c - p;
            if (bests[v].size() < k)
                bests[v].push(nc);
            else if (nc >= bests[v].top()) continue;
            else if (nc < bests[v].top()) {
                bests[v].pop();
                bests[v].push(nc);
            }
            pq.push({-nc, v});
        }
    }
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n+1);
    while (m--) {
        cin >> u >> v >> p;
        adj[u].emplace_back(v, p);
    }
    dijkstra(1);
    vector<ll> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = bests[n].top();
        bests[n].pop();
    }
    for (int i = k-1; i >= 0; --i)
        printf("%lld ", ans[i]);

}
