#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, W; cin >> N >> W;
    vector<vector<long long>> dp(N+1, vector<long long>(W+1));
    // vector<pair<int, int>> items(N);
    // for (int z = 0; z < N; z++) {
    //     int wt, val; cin >> wt >> val;
    //     items[z] = {wt, val};
    // }
    // sort(items.begin(), items.end(), [](auto& a, auto& b) {
    //     return a.first < b.first;
    // });
    for (int r = 1; r <= N; r++) {
        int wt, val; cin >> wt >> val;
        // int wt = items[r-1].first;
        // int val = items[r-1].second;
        for (int c = 1; c <= W; c++) {
            dp[r][c] = dp[r-1][c];
            if (c >= wt) {
                // printf("%d %d: %d\n", r, c, dp[r-1][c-wt]+val);
                dp[r][c] = max(dp[r][c], dp[r-1][c-wt]+val);
            }
        }
    }
    // for (auto x : dp) {
    //     for (auto y : x) cout << y << " ";
    //     cout << endl;
    // }
    cout << dp[N][W] << endl;


}
