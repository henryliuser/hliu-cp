#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> dp;
vector<vector<int>> graph;

// The intuition for max(1 + dp[j]) is that
// you're already going to store adjacency list.
// Hard to do dp[i] = longest path ENDING in i.
// Easier to do dp[i] = longest path starting with i.

int dfs(int x) {
    if (dp[x] != -1) return dp[x];
    if (graph[x].size() == 0) return 0;
    for (auto out : graph[x])
        dp[x] = max(dp[x], 1 + dfs(out));
    return dp[x];
}

int main() {
    int N, M; scanf("%d%d", &N, &M);
    dp.assign(N, -1);
    graph.assign(N, vector<int>{});
    while (M--) {
        int x, y; scanf("%d%d", &x, &y);
        graph[--x].push_back(--y);
    }
    for (int z = 0; z < N; ++z)
        ans = max(ans, dfs(z));

    printf("%d\n", ans);

}
