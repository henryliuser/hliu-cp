// https://atcoder.jp/contests/abc252/tasks/abc252_e
// dijkstra to make a subgraph, then kruskal's mst
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using namespace std;
struct DSU {
    int count;
    vector<int> psz;
    DSU(int n) : count(n), psz(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};
const ll INF = 1e18+5;
#define ti(x) array<ll,x>
#define all(x) begin(x), end(x)
vector<ll> dist, pred;
vector<vector<ti(3)>> graph;
vector<ti(4)> E;
void dijkstra(int src)
{
    dist[src] = 0;
    priority_queue<ti(4)> pq;
    pq.push({0, src, 0, -1});
    while (!pq.empty()) {
        auto [p,u,lc,i] = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;  // same as using seen array
        if (u != src)
            E.push_back( {lc, pred[u], u, i} );
        for (auto [v,c,i] : graph[u]) {
            ll nc = dist[u] + c;
            if (nc < dist[v]) {
                dist[v] = nc;
                pred[v] = u;
                pq.push({-nc,v,c,i});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    dist.assign(N, INF);
    pred.assign(N, -1);
    graph.resize(N);

    for (ll u,v,c, i = 1; i <= M; ++i) {
        cin >> u >> v >> c; --u,--v;
        graph[u].push_back( {v,c,i} );
        graph[v].push_back( {u,c,i} );
    }
    dijkstra(0);

    DSU uf(N);
    sort( all(E) );
    for (auto &t : E) {
        if (uf.unite(t[1], t[2]))
            cout << t[3] << ' ';
        if (uf.count == 1) break;
    }
}
