#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002]{};
int grid[1002][1002]{};

int main() {
    int ans = 0;
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int last = 0;
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; ++i) {  // tough indexing here, we don't use +1's
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++grid[x1][y1];
        --grid[x1][y2];
        --grid[x2][y1];
        ++grid[x2][y2];
    }
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            dp[i+1][j+1] = grid[i][j] + dp[i][j+1];
        }
    }
    int curr = 0;
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            curr += dp[i+1][j+1];
            if (curr == K) ++ans;
        }
    }
    cout << ans << endl;

}
