// https://codeforces.com/problemset/problem/1613/D
// almost solved myself. didnt find the alternating case without digging
// into test cases, which requires an extra layer of DP to account for.
//
// only cases for MEX-correct subsequences are:
// A. all 1's
// B. starts with 0 AND:
//   all consecutive, with adjacent mirrors OK
//     i.e. 0,0,0,1,1,2,3,3,3,4, ...
//   all consecutive with a SINGLE gap at the tail end, CAN THEN ALTERNATE
//     i.e. 0,0,1,2, 4,2,2,2,4,4,2,4, ...   (adjacent mirrors also OK)
//
// let ones count the # of total 1's -- we will deal with case A separately
// let dp[0][x] = # of good seqs starting at 0, ending @ x
// let dp[1][x] = # of good seqs starting at 0, after skipping, ending @ x
// let dp[2][x] = # of good seqs starting at 0, after alternating, ending @ x
// accumulate ans as you fill out the table, then add `modPow(2, ones)-1`

#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 998244353;

vector<vector<ll>> dp;

ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void add(ll &a, ll b) {
    a = (a+b) % MOD;
}

ll solve() {
    ll x, y;
    ll ans = 0, ones = 0;
    int N; cin >> N;
    dp.assign(3, vector<ll>(N+10));
    while (N--) {
        cin >> x;
        if (x == 1) ++ones;  // handle separately

        // dp[0][x]: # of good seqs (starting at 0), ending @ x
        ll z = 1;
        if (x) z = dp[0][x-1];
        y = (dp[0][x] + z) % MOD;
        add(ans, y);
        add(dp[0][x], y);

        // dp[1][x]: # of good seqs after skipping a num, ending @ x
        ll og = 0, on = 0;
        if (x > 1) og = dp[0][x-2];
        if (x > 1) on = dp[2][x-2];
        y = (dp[1][x] + og + on) % MOD;
        add(ans, y);
        add(dp[1][x], y);

        // dp[2][x]: # of good seqs, skipped num, odd cycle, ending @ x
        y = (dp[2][x] + dp[1][x+2]) % MOD;
        add(ans, y);
        add(dp[2][x], y);
    }
    ones = modPow(2, ones, MOD) - 1;
    add(ans, ones);
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
