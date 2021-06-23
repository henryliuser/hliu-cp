#include <bits/stdc++.h>
using namespace std;

int main() {

    int H, W; scanf("%d%d", &H, &W);
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(W+1));
    // dp[r][c] = # of ways to get to (r,c)

    dp[0][1] = 1;
    for (int r = 1; r <= H; ++r) {
        int t = r % 2;
        for (int c = 1; c <= W; ++c) {
            char ch; scanf(" %c", &ch);  // " %c" means skip leading whitespace
            if (ch == '.') dp[t][c] = (dp[!t][c] + dp[t][c-1]) % MOD;
            else dp[t][c] = 0;
        }
    }
    printf("%d\n", dp[H%2][W] % MOD);

}
