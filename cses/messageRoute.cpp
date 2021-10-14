#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll ans = 0;
vector<int> pred;
vector<bool> seen;
vector<vector<int>> graph;

int bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        ++ans;
        int layer = q.size();
        for (int i = 0; i < layer; ++i) {
            int x = q.front();
            q.pop();
            for (int y : graph[x]) {
                if (seen[y]) continue;
                seen[y] = true;
                q.push(y);
                pred[y] = x;
                if (y == n) { return ans + 1; }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    seen.assign(n+1, 0);
    pred.assign(n+1, 0);
    pred[0] = -1;
    seen[1] = true;
    int b = bfs();
    if (b != -1) {
        cout << b << endl;
        vector<int> path;
        while (pred[n] != -1) {
            path.push_back(n);
            n = pred[n];
        }
        for (int i = path.size()-1; i >= 0; --i)
            printf("%d ", path[i]);
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;



}
