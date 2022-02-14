// http://www.usaco.org/index.php?page=viewproblem2&cpid=923
#include <bits/stdc++.h>
using namespace std;

int K, N;
int pre[205][205];
int grid[205][205];

int dpL[205];  // max rect to the left of this line, including x=i
int dpR[205];  // right, including x=i
int dpU[205];  // above, including y=i
int dpD[205];  // below, including y=i

int rsum(int x1, int y1, int x2, int y2) {
    int full = pre[x2][y2];
}

int main() {
    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    cin >> K >> N;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++pre[x1][y1], ++pre[x2+1][y2+1];
        --pre[x1+1][y1], --pre[x1][y2+1];
    }
    for (int x = 0; x <= 200; ++x)
        for (int y = 0; y <= 200; ++y) {
            if (x) dp[x][y] += dp[x-1][y];
            if (y) dp[x][y] += dp[x][y-1];
            if (x && y) dp[x][y] += dp[x-1][y-1];

        }



}
