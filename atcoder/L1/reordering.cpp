// https://atcoder.jp/contests/abc234/tasks/abc234_f
// nice problem
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 998244353;
const ll MXN = 5001;

struct Binomial {
    ll fact[MXN], finv[MXN], minv[MXN];
    Binomial() {
        fact[0] = minv[0] = finv[0] = 1;
        fact[1] = minv[1] = finv[1] = 1;
        for (int i = 2; i < MXN; ++i) {
            fact[i] = i * fact[i-1] % Q;
            minv[i] = Q - Q/i*minv[Q%i] % Q;
            finv[i] = finv[i-1] * minv[i] % Q;
        }
    }
    inline ll operator() (int n, int r) {
        ll v = fact[n] * finv[r] % Q;
        return v * finv[n-r] % Q;
    }
} nCr;

int N, C, z=0;
vector<char> T;
unordered_map<char, int> cnt;
ll dp[26][MXN];

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
        ll v = b * q % Q;
        res = (res + v) % Q;
    }
    dp[i][sz] = res;
    return res % Q;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    N = s.size();
    for (char ch : s) ++cnt[ch];
    C = cnt.size(); T.resize(C);
    for (auto &p : cnt) T[z++] = p.first;

    ll ans = 0;
    for (int sz = 1; sz <= N; ++sz)
        ans = (ans + dfs(0, sz)) % Q;
    cout << ans << "\n";
}
