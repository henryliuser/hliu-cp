#include <bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    int dp[2][3] = {{0, 0, 0}, {0, 0, 0}};
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for (int z = 1; z < N; ++z) {
        for (int a = 0; a < 3; ++a) {
            cin >> dp[1][a];
            vector<int> v;
            for (int b = 0; b < 3; b++) {
                if (b == a) continue;
                v.push_back(b);
            }
            dp[1][a] += max(dp[0][v[0]], dp[0][v[1]]);
        }
        for (int a = 0; a < 3; ++a)
            dp[0][a] = dp[1][a];
    }

    int ans = 0;
    for (int z : dp[0]) ans = max(ans, z);
    cout << ans << endl;



}
