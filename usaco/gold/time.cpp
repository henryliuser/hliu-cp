// very instructive. dp over time (find upper bound)
// iterate over EDGES instead of a branching dfs/bfs search
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

ll ans = 0;
int a, b;
int N, M, C;
ll dp[2][1001];
int main() {
    memset(dp, -1, sizeof dp);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> N >> M >> C;
    vector<pii> edges(M);
    vector<int> weights(N+1);
    for (int i = 1; i <= N; ++i) cin >> weights[i];
    while (M--) cin >> edges[M].f >> edges[M].s;

    dp[0][1] = 0;
    for (int t = 1; t <= 1000; ++t) {
        int q = t % 2;
        memset(dp[q], -1, sizeof dp[q]);
        for (pii e : edges) {
            tie(a, b) = e;
            int w = weights[b];
            if (dp[!q][a] == -1) continue;
            dp[q][b] = max(dp[q][b], dp[!q][a] + w);
        }
        ans = max(ans, dp[q][1] - C * t * t);
    }

    cout << ans << endl;

}
