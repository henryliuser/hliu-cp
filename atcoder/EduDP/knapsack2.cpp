#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000001;

int main() {
    int N, W; scanf("%d%d", &N, &W);
    int w[101], v[101];
    vector<vector<long long>> dp(
        2, vector<long long>(LIM, LLONG_MAX)
    );

    for (int z = 0; z < N; z++)
        scanf("%d%d", w+z, v+z);

    // dp[r][c] = min weight to achieve c value with r items
    dp[0][0] = 0;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < LIM; ++c) {
            dp[1][c] = dp[0][c];
            if (c >= v[r]) {
                auto take = dp[0][c-v[r]] + w[r];
                if (take <= 0) take = LLONG_MAX;
                dp[1][c] = min(dp[1][c], take);
            }
        }
        swap(dp[1], dp[0]);
    }
    int ans = 0;
    for (int z = LIM-1; z >= 0; --z) {
        if (dp[0][z] <= W) {
            ans = z;
            break;
        }
    }
    cout << ans << endl;
}
