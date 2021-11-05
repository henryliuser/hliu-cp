#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

int N, M;
ll dp[1 << 20][20] = {};  // dp[s][i] = # routes that visit s, end in i
vector<vector<int>> adj;

int main() {
    cin >> N >> M;
    int all = (1 << N) - 1;
    adj.resize(N--);
    while (M--) {
        int a, b; cin >> a >> b;
        adj[--b].push_back(--a);  // invert the graph
    }

    dp[1][0] = 1;  // 1 route, visits city 0, ending in city 0
    // ^^^ this base case also ensures we only count routes starting at 1
    for (int S = 3; S <= all; S += 2) {  // skip all without 1
        // bool has1 = S & 1;
        bool hasN = S & (1 << N);
        bool full = S == all;
        // if (!has1) continue;  // subset must include city 1
        if (!full && hasN) continue;  // subset can't have N unless full
        for (int i = 1; i <= N; ++i) {
            int mask = S ^ (1 << i);
            for (int x : adj[i]) {
                bool hasX = S & (1 << x);
                if (!hasX) continue;
                dp[S][i] += dp[mask][x];
                dp[S][i] %= MOD;
            }
        }
    }
    cout << dp[all][N] << endl;
}
