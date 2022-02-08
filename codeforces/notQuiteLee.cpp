/* https://codeforces.com/contest/1610/problem/D
all seq with ANY odd's are good
if the whole sum is odd, simply arrange around 0 to cancel out
if the sum is even, but there exists an odd, you can place that odd around 0
the remaining sum will be odd (E - O = O) which you can place around 0

fun con x = x * (x+1) / 2
S[i] = x[i] + x[i]+1 + ... + x[i]+c[i]-1
     = x[i] * c[i] + con(c[i]-1)

a @ b = a dot b = sum(x*y for x,y in zip(a,b))
good: sum(S) == 0
  => x @ c == -sum map con (c[i]-1 for i..N)

FACT: (ax + by + cz ... == w) iff gcd(a,b,c..) divides w

*/

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int MXN = 2e5+1;
// const int MOD = 1e9+7;
//
// int N;
// ll dp[2][2][MXN], pre[2][2][MXN];
//
// int main() {
//     cin >> N;
//     memset(dp, 0, sizeof dp);
//     for (int i = 1; i <= N; ++i) {
//         ll x; cin >> x;
//         if (i == 1) {
//             if (x%2) dp[1][1][1] = 1;
//             else     dp[0][1][1] = 1;
//         }
//         else if (x % 2 == 1) {
//             dp[0][0][i] = pre[1][1][i-1];
//             dp[0][1][i] = pre[1][0][i-1];
//             dp[1][0][i] = pre[0][1][i-1];
//             dp[1][1][i] = pre[0][0][i-1] + 1;
//         }
//         else if (x % 2 == 0) {
//             dp[0][0][i] = pre[0][1][i-1];
//             dp[0][1][i] = pre[0][0][i-1] + 1;
//             dp[1][0][i] = pre[1][1][i-1];
//             dp[1][1][i] = pre[1][0][i-1];
//         }
//         for (int x : {0,1}) for (int y : {0,1})
//             pre[x][y][i] = (dp[x][y][i] + pre[x][y][i-1]) % MOD;
//     }
//     cout << "even sum even len: ";
//     for (int i = 1; i <= N; ++i) cout << dp[0][0][i] << " "; cout << "\n";
//     cout << "even sum odd  len: ";
//     for (int i = 1; i <= N; ++i) cout << dp[0][1][i] << " "; cout << "\n";
//     cout << "odd  sum even len: ";
//     for (int i = 1; i <= N; ++i) cout << dp[1][0][i] << " "; cout << "\n";
//     cout << "odd  sum odd  len: ";
//     for (int i = 1; i <= N; ++i) cout << dp[1][1][i] << " "; cout << "\n";
//
//     ll ans = 0;
//     // ans = (ans + dp[1][0][N]) % MOD;
//     // ans = (ans + dp[1][1][N]) % MOD;
//     // ans = (ans + dp[0][0][N]) % MOD;
//     for (int i = 1; i <= N; ++i) {
//         ans = (ans + dp[1][0][i]) % MOD;
//         ans = (ans + dp[1][1][i]) % MOD;
//         ans = (ans + dp[0][0][i]) % MOD;
//     }
//
//     cout << ans << "\n";
// }
