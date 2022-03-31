#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, t; cin >> s >> t;
    int M = s.length(), N = t.length();
    vector<vector<pair<int, char>>> dp(
        M+1, vector<pair<int, char>>(N+1, {0, '\0'})
    );
    for (int r = 1; r <= M; ++r) {
        for (int c = 1; c <= N; ++c) {
            if (s[r-1] == t[c-1])
                dp[r][c] = {1 + dp[r-1][c-1].first, s[r-1]};
            else {
                int L = dp[r-1][c].first;
                int U = dp[r][c-1].first;
                if (L >= U) dp[r][c] = {L, dp[r-1][c].second};
                else dp[r][c] = {U, dp[r][c-1].second};
            }
        }
    }
    int x = M, y = N;
    string ans = "";
    while (dp[x][y].first) {
        if (dp[x][y].first == dp[x-1][y].first)
            x--;
        else if (dp[x][y].first == dp[x][y-1].first)
            y--;
        else if (dp[x][y].first == dp[x-1][y-1].first + 1) {
            ans.push_back(dp[x--][y--].second);
        }
    }
    for (int z = dp[M][N].first; z >= 0; --z) {
        if (!ans[z]) continue;
        cout << ans[z];
    }
    cout << endl;

}
