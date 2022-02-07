// http://usaco.org/index.php?page=viewproblem2&cpid=1185
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

}

// sad tle top-down
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int Q = 1e9 + 7;
//
// int N, K;
// vector<int> H;
// int dp[101][1001];
// inline void add(int &x, int y) { x+=y; if (x>Q) x-=Q; }
//
// int dfs(int i, int c) {
//     int &res = dp[i][c];
//     if (c < 0) return 0;
//     if (i == N) return c == 0;
//     if (res != -1) return res;
//     res = 0;
//     for (int h = c; h <= H[i]; ++h) {
//         int x = dfs(i+1, h-c);
//         add(res, x);
//     }
//     return res;
// }
//
// int dfs2(int i, int c) {
//     int &res = dp[i][c];
//     if (i == N-1) return H[i] >= c + K;
//     if (res != -1) return res;
//     res = 0;
//     for (int h = c+K; h <= H[i]; ++h) {
//         int x = dfs2(i+1, h-c-K);
//         add(res, x);
//     }
//     return res;
// }
//
// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     memset(dp, -1, sizeof dp);
//
//     int mn = 1e9;
//     cin >> N; H.resize(N);
//     for (int &x : H) {
//         cin >> x;
//         mn = min(mn, x);
//     }
//     if (N%2 == 0) cout << dfs(0, 0) << '\n';
//     else {
//         int ans = 0;
//         for (K = 0; K <= min(mn, H[N-1]); ++K) {
//             memset(dp, -1, sizeof dp);
//             add( ans, dfs2(0,0) );
//         }
//         cout << ans << '\n';
//     }
//
// }
