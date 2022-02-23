// https://codeforces.com/problemset/problem/489/D
// bfs from each node depth 2 and do some math
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

int N, M;
ll ans = 0;
vector<vector<int>> adj;
void bfs(int src) {
    vector<set<int>> in(N+1);
    queue<int> q;
    q.push(src);
    int depth = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (depth == 1 && v != src) {
                    in[v].insert(u);
                }
                if (depth > 0) continue;
                q.push(v);
            }
        }
        if (++depth > 1) break;
    }
    for (int j = 1; j <= N; ++j) {
        int m = in[j].size();
        ans += m*(m-1)/2;
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    adj.resize(N+1);
    while (M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; ++i)
        bfs(i);

    cout << ans << '\n';
}
