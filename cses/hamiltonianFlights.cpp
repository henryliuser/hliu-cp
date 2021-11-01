#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 0;
// int dp[1 << 20];
unordered_set<int> s;
vector<vector<int>> adj;

void dfs(int u) {
    s.insert(u);
    if (s.size() == N) ++ans;
    for (int v : adj[u])
        if (!s.count(v))
            dfs(v);
    s.erase(u);
}

int main() {
    cin >> N >> M;
    adj.resize(N+1);
    while (M--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    cout << ans << endl;
}
