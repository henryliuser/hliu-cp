// http://usaco.org/index.php?page=viewproblem2&cpid=1185
// if ur dfs has a for loop, maybe need psum in bottom-up
// maybe in digit dp, can do bottom up with psum
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
const int Q = 1e9 + 7;

int pre[1001];
int dp[101][1001];
// k-valid seq => can be reduced to all k's
// dp[i][c] = # of k-vaild seqs in H[:i] where c = cur diff
int add(int x, int y) { return ((x+=y)>Q) ? x-Q : x;  }

int solve() {
    int N; cin >> N;
    vector<int> H(N);
    int mn = 1e9, mx = 0;
    for (int &x : H) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int ans = 0;
    for (int k = 0; k <= mn; ++k) {
        memset(dp, 0, sizeof dp);
        for (int c = 0; c <= mx; ++c)
            dp[N-1][c] = H[N-1] >= c + k;
        for (int i = N-2; i >= 0; --i) {
            pre[0] = 0;
            for (int c = 0; c <= mx; ++c)
                pre[c+1] = add(pre[c], dp[i+1][c]);

            for (int c = 0; c <= mx; ++c)
                dp[i][c] = pre[H[i]-c-k+1];
        }
        if (N%2 == 0) return dp[0][0];
        ans = add(ans, dp[0][0]);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << '\n';
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
