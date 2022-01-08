// https://codeforces.com/problemset/problem/1575/J
// the "stable state" for everything is a chain of 2's
// dp[r][c] keeps track of how many tiles down you can skip
// i think it's O(MN + K). each query will traverse only the non-2's
// and convert them into 2's. Then i try to connect the dp's together
// apparently, didn't need this to pass but whatever.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
vector<vector<int>> grid, dp;

int dfs(int r, int c) {
    int &res = dp[r][c];
    if (r >= N) return c;
    if (res != -1) return dfs(r+res, c);
    int d = grid[r][c];
    grid[r][c] = 2, res = 1;
    if (r+1 < N && dp[r+1][c] != -1)   // sketchy way
        res = 1 + dp[r+1][c];
    if (r-1 >= 0 && dp[r-1][c] != -1)  // of connecting the dp's
        dp[r-1][c] = 1 + res;
    if (d == 1) return dfs(r, c+1);
    if (d == 2) return dfs(r+1, c);
    if (d == 3) return dfs(r, c-1);
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> K;
    dp.assign(N, vector<int>(M, -1));
    grid.assign(N, vector<int>(M));
    for (auto &r : grid)
        for (int &c : r)
            cin >> c;

    for (int c = 0; c < M; ++c) {
        int cur = 1;
        for (int r = N-1; r+1; --r) {
            if (grid[r][c] != 2) cur = -1;
            else cur = max(1, cur);
            dp[r][c] = cur++;
        }
    }

    while (K--) {
        int c; cin >> c;
        cout << 1+dfs(0, c-1) << " ";
    }
    cout << "\n";


}
