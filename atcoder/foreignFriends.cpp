#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

using ll = long long;
using pi = array<ll, 2>;
using rec = pair<pi, pi>;
const int MXN = 1e5+5;

int N, M, K, L;
vector<pi> adj[MXN];

inline bool upd(pi chal, rec &a) {
    pi &f = a.first;
    if (chal[0] < f[0] && chal[1] != f[1]) {
        a.second = f;
        a.first = chal;
        return true;
    }
    pi &s = a.second;
    if (chal[0] < s[0] && chal[1] != s[1])
        a.second = chal;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K >> L;
    set<int> B(L);
    vector<int> A(N);
    for (int &x : A) cin >> x;
    for (int x, i=0; i < L; ++i) {
        cin >> x;
        B.insert(x):
        adj[0].push_back(x,0);  // S --0-> {popular}
    }
    for (ll u,v,c, i=0; i < M; ++i) {
        cin >> u >> v >> c;
        adj[u].emplace_back(v,c);
        adj[v].emplace_back(u,c);
    }

    priority_queue<pi> pq;
    vector<rec> dist(N+1, {{INF,INF}, {INF,INF});
    dist[0] = { {0,0}, {0,0} };

    pq.push( {0,0} );
    while (!pq.empty()) {
        auto [p,u] = pq.top();
        pq.pop();

        int nation = A[u];
        if (dist[])
        for (auto [v,c] : adj[u]) {

        }

    }






}
