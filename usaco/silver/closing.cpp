#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<int> open;
vector<vector<int>> graph;

bool dfs(int u, unordered_set<int> &o) {
    o.erase(u);
    for (int v : graph[u])
        if (o.count(v))
            dfs(v, o);
    return o.empty();
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> N >> M;
    graph.resize(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        open.insert(i);
    for (int i = 0; i < N; ++i) {
        auto o = open;
        cout << (dfs(*begin(o), o) ? "YES" : "NO") << endl;
        int a; cin >> a;
        open.erase(a);
    }
}
