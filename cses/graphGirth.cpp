#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int n, m;
int ans = INT_MAX;
vector<bool> seen;
vector<vector<int>> graph;

int bfs(int x) {
    int res = 0;
    int layer = 0;
    queue<pii> q;  // {u, prev}
    q.push({x, -1});
    seen.assign(n+1, 0);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto p = q.front();
            q.pop();
            for (int v : graph[p.f]) {
                if (v == p.s) continue;
                if (seen[v]) continue;
                if (v == x) return layer+1;
                seen[v] = 1;
                q.push({v, p.f});
            }
        }
        ++layer;
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

    cout << ans << endl;



}
