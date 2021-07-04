#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X; cin >> N >> X;
    const int MOD = 1e9+7;
    vector<int> denom(N);
    vector<long long> dp(X+1);
    for(int& i : denom) cin >> i;
    dp[0] = 1;
    for (auto& d : denom) {
        for (int z = d; z <= X; ++z) {
            dp[z] += dp[z-d];
            dp[z] %= MOD;
        }
    }
    cout << dp[X] << endl;
}
