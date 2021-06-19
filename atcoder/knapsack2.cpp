#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000001;

int main() {
    int N, W; scanf("%d%d", &N, &W);
    int w[101], v[101];
    vector<vector<long long>> dp(
        2, vector<long long>(LIM, 0)
    );

    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 100; ++j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    for (int z = 0; z < N; z++)
        scanf("%d%d", w+z, v+z);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < LIM; ++j) dp[1][j] = LLONG_MAX;
        for (int j = 0; j < LIM; ++j) {
            dp[1][j] = dp[0][j];
            if (j >= v[i-1])
                dp[1][j] = min(dp[1][j], dp[0][j-v[i-1]] + w[i-1]);
        }
        swap(dp[0], dp[1]);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 100; ++j) cout << dp[i][j] << " ";
        cout << endl;
    }
    // int ans = 0;
    // for (int z = 0; z < )
    // printf("%d\n", dp[N][])





}
