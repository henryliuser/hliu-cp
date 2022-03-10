// https://codeforces.com/problemset/problem/1606/E
// https://www.youtube.com/watch?v=Rzmo2VW9vSk&ab_channel=Harisamsharma
// harisam sharma is my savior
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
using namespace std;
using ll = long long;
const int MXN = 501;
const int MOD = 998244353;

int N, X;
ll dp[MXN][MXN];
ll fact[MXN], minv[MXN], finv[MXN];

ll mul(ll a, ll b) { return (a*b)%MOD; }
ll add(ll a, ll b) { return (a+b)%MOD; }
ll pow(ll a, ll b, ll m) {
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

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    memset(fact, 0, sizeof fact);
    fact[0] = minv[0] = finv[0] = 1;
    fact[1] = minv[1] = finv[1] = 1;
    for (int i = 2; i < MXN; ++i) {
        fact[i] = i * fact[i-1] % MOD;
        minv[i] = MOD-MOD/i*minv[MOD%i]%MOD;
        finv[i] = finv[i-1] * minv[i] % MOD;
    }
}

ll nCr(ll n, ll r) {
    ll v = fact[n] * finv[r] % MOD;
    return v * finv[n-r] % MOD;
}

ll dfs(int i, int j) {
    // i remaining heroes, minimum req j health so far
    if (i == 1) return 0;
    if (i == 0) return 1;
    if (j > X) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll res = 0;
    for (int k = 0; k <= i; ++k) {  // k = # of deaths
        ll c = nCr(i, k);           // ways to choose who dies
        ll r = min(i-1, X-j+1);     // range of possible remaining health
        ll p = pow(r, k, MOD);      // ways to choose healths
        ll w = mul(c, p);           // total ways
        ll x = dfs(i-k, j+i-1);     // transition
        res = add(res, mul(w,x));
    }
    return dp[i][j] = res;
}

int main() {
    init();
    cin >> N >> X;
    cout << dfs(N, 1) << '\n';
}
