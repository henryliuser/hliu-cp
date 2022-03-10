// https://cses.fi/problemset/task/1093
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXW = 125250;
const ll Q = 1e9+7;

ll dp[MXW+1] = {};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int sum = N * (N+1) / 2;
    if (sum % 2) {
        cout << "0\n";
        return 0;
    }
    dp[0] = 1;
    for (int x = 1; x <= N; ++x) {
        for (int w = MXW; ~w; --w) {
            if (dp[w] > 0 && w+x <= MXW)
                dp[w+x] = (dp[w+x] + dp[w]) % Q;
        }
    }
    cout << dp[sum/2] / 2 << '\n';
}
