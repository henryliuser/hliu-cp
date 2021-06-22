#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M; scanf("%d%d", &N, &M);
    vector<pair<vector<int>,vector<int>>> graph(N);
    // graph[x].first  -- incoming
    // graph[x].second -- outgoing
    while (M--) {
        int x, y; scanf("%d%d", &x, &y);
        x--, y--;
        graph[y].first.push_back(x);
        graph[x].second.push_back(y);
    }

    vector<int> dp(N, -1);
    vector<int> start;
    for (int z = 0; z < N; ++z) {
        if (graph[z].first.size() == 0) {
            start.push_back(z);
        }
    }
    for (int node : start) {
        dp[node] = 0;
    }



}
