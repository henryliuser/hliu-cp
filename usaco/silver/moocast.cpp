#include <bits/stdc++.h>
using namespace std;
using cow = tuple<int, int, int>;

int N;
vector<bool> seen;
vector<vector<int>> graph;

bool inRange(cow &a, cow &b) {  // b in range of a
    int ax, ay, ap, bx, by, bp;
    tie(ax, ay, ap) = a;
    tie(bx, by, bp) = b;
    ap *= ap;
    int dx = (bx - ax);
    int dy = (by - ay);
    return ap >= (dx * dx + dy * dy);
}

int dfs(int u) {
    int res = 1;
    seen[u] = 1;
    for (int v : graph[u])
        if (!seen[v])
            res += dfs(v);
    return res;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    int ans = 0;
    graph.resize(N);
    vector<cow> cows(N);
    for (int i = 0; i < N; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        cows[i] = {x, y, p};
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (inRange(cows[i], cows[j]))
                graph[i].push_back(j);
        }
    }
    for (int i = 0; i < N; ++i) {
        seen.assign(N, 0);
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}
