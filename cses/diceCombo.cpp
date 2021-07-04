#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    const int MOD = 1e9 + 7;
    vector<long long> dp(N+1);
    dp[0] = 1;
    for (int z = 1; z <= N; ++z) {
        for (int roll = 1; roll <= 6; ++roll) {
            if (z >= roll) {
                dp[z] += dp[z-roll] % MOD;
                dp[z] %= MOD;
            }
            else break;
        }
    }
    printf("%d\n", dp[N] % MOD);

}
