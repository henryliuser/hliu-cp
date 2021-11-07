#include <bits/stdc++.h>
using namespace std;

int N, M;
int T = 0, C = 1;
vector<int> path;
vector<bool> curr;
vector<int> disc, low, scc;
vector<vector<int>> adj;

void tarjan(int u) {
    curr[u] = true;
    int i = path.size();
    path.push_back(u);
    disc[u] = low[u] = T++;
    for (int v : adj[u]) {
        if (disc[v] == -1) {  // if not visited
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (curr[v])  // genius part
            low[u] = min(low[u], disc[v]);
    }
    if (low[u] == disc[u]) {  // found an SCC
        int id = C++;
        for (int j = i; j < path.size(); ++j) {
            scc[path[j]] = id;
            curr[path[j]] = false;
        }
        path.resize(i);
    }
}

void init(int n) {
    adj.resize(n);
    scc.resize(n);
    low.assign(n, -1);
    disc.assign(n, -1);
    curr.assign(n, 0);
}

int main() {
    for (int i = 1; i <= N; ++i)
        if (disc[i] == -1)
            tarjan(i);
}
