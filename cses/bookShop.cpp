#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, X; cin >> N >> X;
    vector<int> price(N), pages(N);
    for (auto& p : price) cin >> p;
    for (auto& p : pages) cin >> p;
    vector<vector<int>> dp(2, vector<int>(X+1));

    for (int r = 1; r <= N; ++r) {
        int t = r % 2;
        int w = price[r-1];
        int p = pages[r-1];
        for (int c = 1; c <= X; ++c) {
            dp[t][c] = dp[!t][c];
            if (c >= w)
                dp[t][c] = max(dp[t][c], p + dp[!t][c-w]);
        }
    }
    cout << dp[N%2][X] << endl;
}
