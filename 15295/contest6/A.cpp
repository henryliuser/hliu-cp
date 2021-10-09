#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int a, b, w;
int main() {
    int n, m; cin >> n >> m;
    vector<unordered_map<int, int>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        if (a==b) continue;
        if (!graph[a].count(b)) {
            graph[a][b] = w;
            graph[b][a] = w;
        }
        else {
            graph[a][b] = min(w, graph[a][b]);
            graph[b][a] = min(w, graph[b][a]);
        }
    }
    cin.clear();
    priority_queue<pii> pq;
    vector<int> dist(n+1, INT_MAX);
    vector<bool> seen(n+1);
    vector<int> pred(n+1);
    pq.push({1,1});
    dist[1] = 0;
    pred[1] = -1;
    while (!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        if (u.s == n) break;
        if (seen[u.s]) continue;
        seen[u.s] = true;
        for (auto v : graph[u.s]) {
            int nc = v.s + dist[u.s];
            if (nc < dist[v.f]) {
                dist[v.f] = nc;
                pq.push({-nc, v.f});
                pred[v.f] = u.s;
            }
        }
    }
    if (dist[n] == INT_MAX) printf("-1\n");
    else {
        vector<int> path;
        for (int i = n; i != -1; i = pred[i])
            path.push_back(i);
        for (int i = path.size() - 1; i >= 0; --i)
            printf("%d ", path[i]);
    }

}
