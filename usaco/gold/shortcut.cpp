#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

int N, M, T;
vector<bool> seen;
vector<ll> dist, cnt;
vector<int> cows, pred;
vector<vector<pii>> graph;

ll dfs(int u, vector<vector<int>> &tree) {
    ll res = cows[u];
    for (int v : tree[u])
        res += dfs(v, tree);
    cnt[u] = res;
    return res;
}

void dijkstra() {
    seen.resize(N+1);
    pred.assign(N+1, -1);
    dist.assign(N+1, LLONG_MAX);
    priority_queue<pii> pq;
    dist[1] = 0, pred[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().s;
        pq.pop();
        if (seen[u]) continue;
        seen[u] = 1;
        for (pii &v : graph[u]) {
            int nc = dist[u] + v.s;
            bool lex = (nc == dist[v.f] && u < pred[v.f]);
            if (nc < dist[v.f] || lex) {
                pred[v.f] = u;
                dist[v.f] = nc;
                pq.push({-nc, v.f});
            }
        }
    }
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin >> N >> M >> T;
    cows.resize(N+1);
    graph.resize(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> cows[i];
    for (int i = 0; i < M; ++i) {
        int a,b,t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    dijkstra();
    cnt.resize(N+1);
    vector<vector<int>> tree(N+1);
    for (int i = 2; i <= N; ++i)
        if (pred[i] != -1)
            tree[pred[i]].push_back(i);
    dfs(1, tree);
    ll ans = 0;
    for (int i = 2; i <= N; ++i)
        ans = max(ans, cnt[i] * (dist[i] - T));

    cout << ans << endl;
}
