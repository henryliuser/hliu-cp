#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    queue<int> q;
    int N; cin >> N;
    vector<int> indeg(N);
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
        int k; cin >> k;
        indeg[i] = k;
        if (!k) q.push(i);
        while (k--) {
            int y; cin >> y;
            adj[y-1].push_back(i);
        }
    }

    int cnt = 0, depth = 0;
    vector<bool> seen(N);
    while (!q.empty()) {
        int sz = q.size();
        priority_queue<int> pq;
        while (sz--) { pq.push(-q.front()); q.pop(); }
        while (!pq.empty()) {
            int u = -pq.top();
            pq.pop();
            seen[u] = 1;
            for (int v : adj[u]) {
                if (--indeg[v]) continue;
                if (seen[v]) continue;
                seen[v] = 1;
                if (v < u) q.push(v);
                if (v > u) pq.push(-v);
            }
            ++cnt;
        }
        ++depth;
    }
    if (cnt < N) return -1;
    return depth;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
