#include <bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    vector<int> stones(N), dp(N);
    for (int z = 0; z < N; z++)
        cin >> stones[z];

    for (int z = 1; z < N; z++) {
        dp[z] = abs(stones[z] - stones[z-1]) + dp[z-1];
        if (z == 1) continue;
        int c = abs(stones[z] - stones[z-2]) + dp[z-2];
        dp[z] = min(dp[z], c);
    }
    cout << dp[N-1] << endl;

}
