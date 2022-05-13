// https://atcoder.jp/contests/abc250/tasks/abc250_h
// for each edge {u,v,c}, adjust the cost c to be c'
// c' = c + dist[u] + dist[v]
// where dist[x] = shortest path from any house to x
// now, for some query {x,y,t} we may consider all and only
// the edges such that c' <= t. Intuitively, an edge is not okay to use
// if including it will introduce a new path from h(u) to h(v) with cost > t
// where h(x) is the nearest house to node x.
// after computing c', sort edges by c' and queries by t.
// run 2 pointers and use DSU to tell if each x and y are in the same component.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXN = 2e5+5;
const ll INF = 1e18+5;
#define ti(x) array<ll, x>
#define all(x) begin(x), end(x)

int N, M, K;
ll dist[MXN];
bitset<MXN> ans;
vector<ti(2)> adj[MXN];

struct DSU {
    int count;
    vector<int> psz;
    DSU(int n) : count(n), psz(n, -1) {}
    inline bool unite(int a, int b) {
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
    inline bool same(int a, int b) {
        return find(a) == find(b);
    }
};

void dijkstra() {
    priority_queue<ti(2)> pq;
    for (int u = 1; u <= K; ++u)
        pq.push( {0,u} ),
        dist[u] = 0;

    while (!pq.empty()) {
        auto [p,u] = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            ll nc = w - p;
            if (nc < dist[v])
                dist[v] = nc,
                pq.push( {-nc,v} );
        }
    }
}

void solve() {
    cin >> N >> M >> K;
    vector<ti(3)> edges(M);
    for (ll a,b,c, i=0; i < M; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back( {b,c} );
        adj[b].push_back( {a,c} );
        edges[i] = {c,a,b};
    }

    int T; cin >> T;
    vector<ti(4)> Q(T);
    for (int i=0; i < T; ++i)
        cin >> Q[i][1] >> Q[i][2] >> Q[i][0],
        Q[i][3] = i;

    dijkstra();
    for (auto &[c,u,v] : edges)
        c = c + dist[u] + dist[v];  // c => c'

    DSU uf(N+1);
    sort( all(Q) );
    sort( all(edges) );
    for (int i=0, j=0; j < T; ++j) {
        auto [t,x,y,q] = Q[j];
        while (i < M && edges[i][0] <= t) {
            auto [c,u,v] = edges[i++];
            uf.unite(u, v);
        }
        ans[q] = uf.same(x, y);
    }
    for (int i = 0; i < T; ++i)
        cout << (ans[i] ? "Yes" : "No") << '\n';
}

int main() {
    fill(dist, dist+MXN, INF);
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
