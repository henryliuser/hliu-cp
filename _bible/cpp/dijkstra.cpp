#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

// set-up
int N;
vector<int> pred(N, -1);
vector<int> dist(N, INT_MAX);

// adjacency list
vector<vector<pii>> graph; // pair<target, weight>

void dijkstra(int src)
{
    int p, u;
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        tie(p, u) = pq.top();
        pq.pop();
        if (-p != dist[u]) continue;  // same as using seen array
        for (pii &v : graph[u]) {
            int nc = dist[u] + v.s;
            if (nc < dist[v.f]) {
                dist[v.f] = nc;
                pred[v.f] = u;
                pq.push({-nc, v.f});
            }
        }
    }
}
