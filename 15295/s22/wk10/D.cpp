// 
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int dp[101][101][101];
int main() {
    memset(dp, 0, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    string S, T, V;
    cin >> S >> T >> V;
    int N = S.size();
    int M = T.size();
    int K = V.size();
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            for (int k = 0; k < K; ++k) {
                int &r = dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                char a = S[i-1];
                char b = T[j-1];
                if (a == b) {
                    r = max(1 + dp[i-1][j-1][k-1]);
                }
            }


}
