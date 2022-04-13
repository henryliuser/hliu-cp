#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXN = 3e5+5;

int N, M;
char who[MXN] = {};
vector<int> adj[MXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    who[N-1] = 1;
    queue<int> q;
    q.push(N-1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (who[v]) continue;
            if (v == N) continue;  // already taken by A
            who[v] = 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << char(who[i]+'A');
}
