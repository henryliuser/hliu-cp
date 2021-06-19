#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, W; cin >> N >> W;
    vector<vector<long long>> dp(2, vector<long long>(W+1));
    for (int r = 0; r < N; r++) {
        int wt, val; cin >> wt >> val;
        for (int c = 1; c <= W; c++) {
            dp[1][c] = dp[0][c];
            if (c >= wt) {
                dp[1][c] = max(dp[1][c], dp[0][c-wt]+val);
            }
        }
        dp[0] = dp[1];
    }
    cout << dp[1][W] << endl;


}
