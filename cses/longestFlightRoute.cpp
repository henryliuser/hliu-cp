#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5+1;

int ans = 0;
int N, M, a, b;
vector<int> dp, succ;
vector<vector<int>> adj;

int dfs(int u)  {
    if (dp[u] != -1) return dp[u];
    if (u == N) return 1;
    int len = -2;
    for (int v : adj[u]) {
        int q = dfs(v);
        if (q == -2) continue;
        if (q+1 > len) {
            len = q+1;
            succ[u] = v;
        }
    }
    dp[u] = len;
    return dp[u];
}

void init() {
    adj.resize(N+1);
    dp.assign(N+1, -1);
    succ.assign(N+1, -1);
}

int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    a = dfs(1), b = 1;
    if (a == -2) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    cout << a << endl;
    while (succ[b] != -1) {
        printf("%d ", b);
        b = succ[b];
    }
    printf("%d\n", b);
}
