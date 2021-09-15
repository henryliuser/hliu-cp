#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int r, c, cost;
    vector<Node*> adj;
    Node(int a, int b, int c) : r(a), c(b), cost(c) {};
};

int n, m, x, y;
vector<int> maxDist, cost;
vector<vector<pair<int, int>>> roads;
vector<vector<Node*>> graph;

Node* dfs(int p, int remain, Node* prev, int src) {
    Node* curr = new Node(src, p, cost[p]);
    if (prev) prev->adj.push_back(curr);
    graph[src][p] = curr;
    if (p == y) return nullptr;
    for (auto& it : roads[x]) {
        int q = it.first;
        int l = it.second;
        dfs(q, maxDist[q], curr, q);
        if (l <= remain)
            dfs(q, remain-l, curr, p);
    }
    return curr;
}

vector<vector<ll>> dijkstra() {
    vector<vector<bool>> seen(n, vector<bool>(n));
    vector<vector<ll>>   dist(n, vector<ll>(n, LLONG_MAX));
    priority_queue<tuple<ll, int, int>> pq;
    pq.push({0, x, x});
    dist[x][x] = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        int p = get<0>(t);
        int r = get<1>(t);
        int c = get<2>(t);
        if (seen[r][c]) continue;
        seen[r][c] = true;
        for (auto& o : graph[r][c]->adj) {
            ll nc = dist[r][c] + o->cost;
            if (nc < dist[r][c]) {
                dist[r][c] = nc;
                pq.push({nc, o->r, o->c});
            }
        }
    }
    return dist;
}

int main() {
    ll ans = 0;
    cin >> n >> m >> x >> y;
    roads.resize(n);
    maxDist.resize(n); cost.resize(n);
    for (int z = 0; z < m; ++z) {
        int u, v, w; cin >> u >> v >> w;
        roads[u].push_back({v, w});
    }
    for (int z = 0; z < m; ++z) {
        cin >> maxDist[z] >> cost[z];
    }
    dfs(x, maxDist[x], nullptr, x);
    auto dist = dijkstra();
    for (int r = 0; r < n; ++r) {
        ans = min(ans, dist[r][y]);
    }
    cout << ans << endl;

}
