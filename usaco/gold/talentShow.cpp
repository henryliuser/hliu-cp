// http://www.usaco.org/index.php?page=viewproblem2&cpid=839
// same idea as AtCoder Average and Median
// https://atcoder.jp/contests/abc236/tasks/abc236_e
// binary search on the answer
// sum(T) / sum(W) >= g
// sum(T) >= g * sum(W)
// sum(T) - g*sum(W) >= 0
// sum(T[i] - g*W[i] for i in range(N)) >= 0
// knapsack dp to check
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

ll N, W;
ll tot = 0;
ll dp[1001];
ll A[251], T[251];

bool check(int g) {
    for (ll &x : dp) x = -INF;

    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        ll val = T[i]*1000 - A[i]*g;
        for (ll j = W; j >= 0; --j) {
            if (dp[j] == -INF) continue;
            ll nw = min(W, j + A[i]);
            dp[nw] = max(dp[nw], dp[j]+val);
        }
    }
    return dp[W] >= 0;
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> T[i];
        tot += T[i];
    }

    ll lo = 0, hi = 3e8;
    while (lo < hi) {
        ll mid = lo + (hi-lo+1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << '\n';
}


// this solution passes all cases, but it's Wrong :(
// min weight at each talent level is optimal for ratio
// but it may NOT pass the W threshold.

// knapsack over talent instead of weight, since that bound is lower
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const ll INF = 1e18;
// const int MXT = 250000;
//
// ll dp[MXT];
// // dp[x] = min weight to reach talent x
// // i think maybe you have to compute answer as you go.
// // the dp table may not contain the answer at the end, perhaps
// // since if ur only storing the minimum, then some talent levels
// // won't cross the threshold of W, meaning you'll skip considering them.
//
// int main() {
//     freopen("talent.in", "r", stdin);
//     freopen("talent.out", "w", stdout);
//     cin.tie(0)->sync_with_stdio(0);
//
//     ll tot = 0;
//     int N, W; cin >> N >> W;
//     vector<ll> A(N), T(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i] >> T[i];
//         tot += T[i];
//     }
//     for (ll &x : dp) x = INF;
//
//     dp[0] = 0;
//     double ans = 0.0;
//     for (int i = 0; i < N; ++i) {
//         for (int j = tot; j >= 0; --j) {
//             // loop backwards, avoids storing dp[i][x]
//             if (dp[j] == INF) continue;
//             int nt = j + T[i];
//             ll &u = dp[nt];
//             u = min(u, dp[j] + A[i]);
//             if (u >= W) ans = max(ans, 1.0*nt/u);
//         }
//     }
//     cout << floor(ans * 1000) << '\n';
// }
