#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    const int MOD = 1e9 + 7;
    vector<int> denom(N);
    vector<long long> dp(X+1);
    for (int z = 0; z < N; ++z) {
        cin >> denom[z];
    }
    dp[0] = 1;
    for (int z = 1; z <= X; ++z) {
        for (auto& d : denom) {
            if (z-d >= 0) {
                dp[z] += dp[z-d] % MOD;
                dp[z] %= MOD;
            }
        }
    }
    cout <<  dp[X] % MOD << endl;

}
