// https://atcoder.jp/contests/abc234/tasks/abc234_f
// nice problem
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll MXN = 5001;

int N, C, z=0;
vector<char> T;
unordered_map<char, int> cnt;
ll fact[MXN], minv[MXN], finv[MXN];
ll dp[26][MXN];

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    memset(fact, 0, sizeof 0);
    fact[0] = fact[1] = finv[0] = finv[1] = minv[0] = minv[1] = 1;
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

ll dfs(int i, ll sz) {
    if (sz == 0) return 1;
    if (i >= C) return 0;
    if (dp[i][sz] != -1)
        return dp[i][sz];
    ll res = 0;
    ll c = cnt[ T[i] ];
    for (int j = min(sz, c); j+1; --j) {
        ll b = nCr(sz, j);
        ll q = dfs(i+1, sz-j);
        ll v = b * q % MOD;
        res = (res + v) % MOD;
    }
    dp[i][sz] = res;
    return res % MOD;
}

int main() {
    init();
    string s; cin >> s;
    N = s.size();
    for (char ch : s) ++cnt[ch];
    C = cnt.size(); T.resize(C);
    for (auto &p : cnt) T[z++] = p.first;

    ll ans = 0;
    for (int sz = 1; sz <= N; ++sz)
        ans = (ans + dfs(0, sz)) % MOD;
    cout << ans << "\n";
}
