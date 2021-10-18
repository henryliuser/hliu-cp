#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int n, m;
int ans = INT_MAX;
vector<vector<int>> graph;

int bfs(int x) {
    int res = INT_MAX;
    int layer = 0;
    vector<int> dist(n+1, -1);
    queue<pii> q;  // {u, prev}
    q.push({x, -1});
    while (!q.empty()) {
        ++layer;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto p = q.front();
            q.pop();
            for (int v : graph[p.f]) {
                if (v == p.s) continue;
                if (dist[v] != -1) {
                    res = min(res, layer + dist[v]);
                    continue;
                }
                if (v == x) res = min(res, layer);
                dist[v] = layer;
                q.push({v, p.f});
            }
        }
    }
    return res;
}


int main() {
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        ans = min(ans, bfs(i));

    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

}
