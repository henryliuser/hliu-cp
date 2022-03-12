#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
#define tl(x) array<ll, x>
const ll inf = 1e18+5;

int N, M;
map<int, ll> adj[301];
vector<vector<map<int,ll>>> spt;
vector<vector<ll>> dist;

template<class T, class A>
void dijkstra(int src, vector<ll> &dist, T &tree, A &adj) {
    ll p, u;
    dist[src] = 0;
    priority_queue<pl> pq;
    pq.push( {0, src} );
    while (!pq.empty()) {
        tie(p,u) = pq.top();
        pq.pop();
        // if (-p != dist[u]) continue;
        for (auto &[v,c] : graph[u]) {
            ll nc = -p + c;
            if (nc > dist[v]) continue;
            t[u][v] = c;
            dist[v] = nc;
            pq.push( {-nc, v} );
        }
    }
    return dist;
}
template <class A>
void dijkstra(int src, vector<ll> &dist, A &adj) {
    ll p, u;
    dist[src] = 0;
    priority_queue<pl> pq;
    pq.push( {0, src} );
    while (!pq.empty()) {
        tie(p,u) = pq.top();
        pq.pop();
        // if (-p != dist[u]) continue;
        for (auto &[v,c] : graph[u]) {
            ll nc = -p + c;
            if (nc > dist[v]) continue;
            dist[v] = nc;
            pq.push( {-nc, v} );
        }
    }
    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    vector<tl(3)> edges(M);
    spt.resize(N+1, vector<map<int,ll>>(N+1));
    dist.assign(N+1, vector<ll>(N+1, inf));

    for (ll u,v,c, i=0; i < N; ++i) {
        cin >> u >> v >> c;
        adj[u][v] = c;
        adj[v][u] = c;
        edges[i] = {u,v,c};
    }

    for (int u = 1; u <= N; ++u)
        dijkstra(u, dist[u], spt[u], adj);

    int ans = 0;
    for (auto [u,v] : edges) {
        vector<ll> du(N+1, inf), dv(N+1, inf);
        dijkstra(u, du, spt[u]);
        bool ok = 1;
        for (int i = 1; i <= N; ++i)
            if (du[i] != dist[u][i]) {
                ok = 0;
                break
            }
        if (!ok) continue;
        dijkstra(v, dv, spt[v]);
        for (int i = 1; i <= N; ++i)
            if (dv[i] != dist[v][i]) {
                ok = 0;
                break;
            }
        if (!ok) continue;
        ++ans;
    }
    return ans;


}
