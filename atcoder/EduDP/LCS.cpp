#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, t; cin >> s >> t;
    int M = s.length(), N = t.length();
    vector<vector<int>> dp(M+1, vector<int>(N+1));
    for (int r = 1; r <= M; ++r) {
        for (int c = 1; c <= N; ++c) {
            if (s[r-1] == t[c-1])
                dp[r][c] = 1 + dp[r-1][c-1];
            else
                dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
        }
    }
    int x = M, y = N;
    string ans = "";
    while (dp[x][y]) {
        if (dp[x][y] == dp[x-1][y]) x--;
        else if (dp[x][y] == dp[x][y-1]) y--;
        else if (dp[x][y] == 1 + dp[x-1][y-1])
            ans.push_back(s[x--]), y--;
    }
    for (int z = dp[M][N]; z >= 0; --z)
        cout << ans[z];
    cout << endl;

}
