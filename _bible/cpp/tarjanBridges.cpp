#include <bits/stdc++.h>
using namespace std;

int N, T = 0; // number of nodes
vector<int> disc, low;   // discovery time, low link value
vector<vector<int>> adj, ans; // graph, bridge edge list

void tarjan(int u, int p = -1) {
    disc[u] = low[u] = T++;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (disc[v] != -1)
            low[u] = min(low[u], disc[v]);
        else {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                // (u -> v) is a bridge
                ans.push_back( {u,v} );
            }
        }
    }
}

void init() {
    adj.resize(N);
    low.resize(N);
    disc.assign(N, -1);
}

int main() {
    init(n);
    vector<vector<int>> connections = { {0,1}, {1,2}, {2,0}, {1,3} };
    for (auto c : connections) {
        int a = min(c[0], c[1]);
        int b = max(c[0], c[1]);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjan(0);
}
