#include <bits/stdc++.h>
using namespace std;

int N, numCycles = 0;
vector<int> color, mark, pred;
vector<vector<int>> adj, cycles;

void dfs(int u, int p) {
    if (color[u] == 2) return;
    if (color[u] == 1) {
        int curr = p;
        mark[curr] = ++numCycles;
        while (curr != u) {
            curr = pred[curr];
            mark[curr] = numCycles;
        }
        return;
    }
    pred[u] = p;
    color[u] = 1;  // partially visited
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    color[u] = 2;  // fully visited
}

void init() {
    mark.resize(N);
    pred.resize(N);
    color.resize(N);
}

int main() {
    N = 4;
    init();
    adj = {{1,2}, {0,2,3}, {0,1}, {1}};
    dfs(0, -1);
    cycles.resize(numCycles);
    for (int i = 0; i < N; ++i) {
        if (mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }
    for (auto c : cycles) {
        for (auto x : c)
            printf("%d ", x);
        printf("\n");
    }

}
