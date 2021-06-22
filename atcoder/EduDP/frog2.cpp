#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K; cin >> N >> K;
    vector<int> stones(N), dp(N, 0);
    for (int z = 0; z < N; z++)
        cin >> stones[z];

    for (int z = 1; z < N; z++) {
        dp[z] = INT_MAX;
        for (int k = 1; k <= min(z, K); ++k) {
            dp[z] = min(dp[z], abs(stones[z] - stones[z-k]) + dp[z-k]);
        }
    }
    cout << dp[N-1] << endl;

}
