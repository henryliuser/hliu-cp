#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int main() {

    int N, M; cin >> N >> M;
    vector<vector<long long>> dp(N, vector<long long>(M+1));
    long long ans = 0;
    int first; cin >> first;
    if (first == 0) for (int z = 1; z <= M; ++z) dp[0][z] = 1;
    else dp[0][first] = 1;
    for (int r = 1; r < N; ++r) {
        int x; cin >> x;
        for (int c : {r-1, r, r+1}) {
            if (x == 0)
        }
        for (int c = 1; c <= M; ++c) {
            // printf("%d %d %d\n", r,c,x);
            if (x == 0 || x == c) {
                dp[r][c] = dp[r-1][c-1] + dp[r-1][c] + dp[r-1][c+1];
            }
        }
    }
    // for (auto x: dp) {
    //     for (auto y : x) printf("%d ", y);
    //     printf("\n");
    // }
    for (int z = 1; z <= M; ++z)
        ans += dp[N-1][z];
    cout << ans % MOD << endl;

}
