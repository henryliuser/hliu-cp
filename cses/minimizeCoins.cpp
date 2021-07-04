#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, X; cin >> N >> X;
    vector<int> dp(X+1, INT_MAX), coins(N);
    for (int z = 0; z < N; ++z)
        cin >> coins[z];

    dp[0] = 0;
    for (int z = 1; z <= X; ++z) {
        for (int& c : coins) {
            if (z - c >= 0) {
                int last = dp[z-c];
                if (last == INT_MAX) continue;
                dp[z] = min(dp[z], last+1);
            }
        }
    }
    if (dp[X] == INT_MAX) dp[X] = -1;
    cout << dp[X] << endl;

}
