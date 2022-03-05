#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 1e9 + 7;
#define popcnt(x) __builtin_popcount(x)

int ok[22][22] = {};
ll dp[1 << 21] = {};
void add(ll &a, ll b) { if ((a+=b) >= Q) a -= Q; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> ok[i][j];

    dp[0] = 1;
    int p = 1 << N;
    for (int m = 0; m < p; ++m) {
        int pc = popcnt(m);
        for (int b = 0; b < N; ++b) {
            if (m & (1<<b)) continue;
            if (!ok[pc][b]) continue;
            int t = m | (1 << b);
            add(dp[t], dp[m]);
        }
    }

    cout << dp[p-1] << '\n';
}
