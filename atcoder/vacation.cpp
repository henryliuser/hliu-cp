#include <bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    vector<vector<int>> dp(N, vector<int>(3));
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for (int z = 1; z < N; ++z)
        for (int a = 0; a < 3; ++a) {
            cin >> dp[z][a];
            vector<int> v;
            for (int b = 0; b < 3; b++) {
                if (b == a) continue;
                v.push_back(b);
            }
            dp[z][a] += max(dp[z-1][v[0]], dp[z-1][v[1]]);
        }
    int ans = 0;
    for (int z : dp[N-1]) ans = max(ans, z);
    cout << ans << endl;



}
