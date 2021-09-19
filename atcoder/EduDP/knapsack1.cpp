#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, W; cin >> N >> W;
    vector<vector<ll>> dp(2, vector<ll>(W+1));
    for (int r = 1; r <= N; ++r) {
        int t = r%2;
        int wt, val; cin >> wt >> val;
        for (int c = 1; c <= W; ++c) {
            dp[t][c] = dp[!t][c];
            if (c < wt) continue;
            dp[t][c] = max(dp[t][c], val + dp[!t][c-wt]);
        }
    }
    cout << dp[N%2][W] << endl;

}
