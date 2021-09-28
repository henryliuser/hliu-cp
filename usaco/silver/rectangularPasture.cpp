#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define R first
#define C second

int N;
vector<pii> cows;
vector<vector<int>> grid;

int sum2D(int r1, int c1, int r2, int c2) {
    int all  = grid[r2][c2];
    int left = grid[r2][c1-1];
    int top  = grid[r1-1][c2];
    int over = grid[r1-1][c1-1];
    return all - left - top + over;
}

int main() {
    // input
    cin >> N;
    ll ans = N+1;
    cows.resize(N);
    grid.assign(N+2, vector<int>(N+2));
    for (int i = 0; i < N; ++i)
        cin >> cows[i].R >> cows[i].C;

    // coordinate compression
    auto cmp = [](pii& a, pii& b) { return a.C < b.C; };
    sort(begin(cows), end(cows), cmp);
    for (int i = 0; i < N; ++i) cows[i].C = i+1;
    sort(begin(cows), end(cows));
    for (int i = 0; i < N; ++i) {
        cows[i].R = i+1;
        grid[cows[i].R][cows[i].C] = 1;
    }
    // 2d prefix sum
    for (int i = 1; i <= N+1; ++i) {
        for (int j = 1; j <= N+1; ++j) {
            int up = grid[i-1][j];
            int left = grid[i][j-1];
            int diag = grid[i-1][j-1];
            grid[i][j] += up + left - diag;
        }
    }
    // iterate on top and bottom, count subsets
    for (int i = 0; i < N; ++i) {
        auto& top = cows[i];
        for (int j = i+1; j < N; ++j) {
            auto& bot = cows[j];
            int left  = min(top.C, bot.C) - 1;
            int lsum  = sum2D(top.R, 1, bot.R, left) + 1;
            int right = max(top.C, bot.C) + 1;
            int rsum  = sum2D(top.R, right, bot.R, N+1) + 1;
            ans += lsum * rsum;
        }
    }
    cout << ans << endl;

}
