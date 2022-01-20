// https://atcoder.jp/contests/abc235/tasks/abc235_f
// TLE + MLE sadness
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

string S;  // N
ll N, M, full;
unordered_map<ll, ll> C;
// ll dp[MXN][11][1025][2][2];
vector<vector<vector<vector<vector<ll>>>>> dp;
vector<ll> p10;

ll add(ll x, ll y) { return (x+y) % MOD; }
ll mul(ll x, ll y) { return (x*y) % MOD; }

ll dfs(ll i, ll t, ll m, bool u, bool s) {
    if (i == N && m == full) return !s;
    if (i >= N) return 0;
    if (dp[i][t][m][u][s] != -1) return dp[i][t][m][u][s];

    ll res[] = {0,0};
    ll k = (t<10) ? t : (S[i]-'0');
    for (ll j = 0; j <= k; ++j) {
        ll nt = 9 + (t == 10 && j == k);
        ll bit = m;
        bool u0 = (u || j > 0);
        if (C.count(j) && u0)
            bit |= (1 << C[j]);
        ll cnt = dfs(i+1, nt, bit, u0, 0);
        ll w = mul(p10[N-i-1], j);
        ll sum = dfs(i+1, nt, bit, u0, 1);
        res[1] = add(res[1], sum);
        res[1] = add(res[1], mul(cnt, w));
        res[0] = add(res[0], cnt);
    }
    dp[i][t][m][u][0] = res[0];
    dp[i][t][m][u][1] = res[1];
    return res[s];
}

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // memset(dp, -1, sizeof dp);
    ll j = 0;
    cin >> S >> M;
    N = S.size();
    dp.assign(N,
        vector<vector<vector<vector<ll>>>>(11,
            vector<vector<vector<ll>>>(1025,
                vector<vector<ll>>(2,
                    vector<ll>(2, -1))
            )
        )
    );
    full = (1 << M) - 1;
    for (ll i = 0; i < M; ++i) {
        ll x; cin >> x;
        C[x] = j++;
    }
    p10.resize(N+1);
    p10[0] = 1;
    for (ll i = 1; i <= N; ++i)
        p10[i] = mul(p10[i-1], 10);
}


int main() {
    init();
    cout << dfs(0, 10, 0, 0, 1) << '\n';
}
