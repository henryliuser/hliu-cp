// https://codeforces.com/contest/1581/problem/C
// 2d kadane's. if it's better to reset, then reset.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pre[405][405];

inline int rsum(int r1, int c1, int r2, int c2) {
    int full = pre[r2][c2], smol = pre[r1-1][c1-1];
    int left = pre[r2][c1-1], abov = pre[r1-1][c2];
    return full - left - abov + smol;
}

inline int score(int r1, int c1, int r2, int c2) {
    int a = r2-r1-1, b = c2-c1-1;
    int left  = a - rsum(r1+1, c1, r2-1, c1);
    int right = a - rsum(r1+1, c2, r2-1, c2);
    int top   = b - rsum(r1, c1+1, r1, c2-1);
    int below = b - rsum(r2, c1+1, r2, c2-1);
    int mid   = rsum(r1+1, c1+1, r2-1, c2-1);
    return left + right + top + below + mid;
}

ll solve() {
    int ans = 1e9;
    int N, M; cin >> N >> M;
    for (int i = 0; i <= (N+1)*(M+1); ++i)
        pre[0][i] = 0;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            char x; cin >> x;
            pre[i][j] = (x-'0') + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }

    for (int c1 = 1; c1 <= M; ++c1)
        for (int c2 = c1+3; c2 <= M; ++c2) {
            int r1 = 1;
            for (int r2 = 5; r2 <= N; ++r2) {
                int x = score(r1, c1, r2, c2);
                int y = score(r2-4, c1, r2, c2);
                if (y < x) r1 = r2-4;  // kadane's magic
                ans = min({ans, x, y});
            }
        }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
