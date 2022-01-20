// https://atcoder.jp/contests/abc235/tasks/abc235_f
// top-down bitmask digit dp
// lessons:
// 1. tight (for digit dp) can just be boolean
// 2. function calls are not free
// 3. hashing is slow as shit
// 4. do bottom up.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MXN = 1e4+5;
const ll MOD = 998244353;

string S;  // N
ll M, N, full=0;
ll dp[2][MXN][2][2][1024];  // [count/sum] [i][t][u] [mask]
ll p10[MXN];  // store powers of 10 % MOD
int C[10];

inline void add(ll &x, ll y) { x=(x+y)%MOD; }
inline ll mul(ll x, ll y) { return (x*y)%MOD; }

ll dfs(int i, bool t, bool u, int m) {
    // i: index  t: tight  u: can_use_0  m: mask
    // returns the COUNT of suitable numbers
    if (i == N && m == full) return 1;
    if (i >= N) return 0;
    if (dp[0][i][t][u][m] != -1) return dp[0][i][t][u][m];

    ll res[] = {0, 0};
    int k = (t) ? (S[i]-'0') : 9;  // digit restrictions
    for (int j = 0; j <= k; ++j) {
        bool nt = t && (j==k);
        bool nu = (j > 0 || u);
        ll bit = m;
        if (nu && C[j] != -1)
            bit |= (1 << C[j]);
        ll cnt = dfs(i+1, nt, nu, bit);
        ll sum = dp[1][i+1][nt][nu][bit];
        ll p = mul(p10[N-i-1], j);  // (10^i) * (selected digit)
        add(res[1], sum);
        add(res[1], mul(cnt,p));
        add(res[0], cnt);
    }
    dp[0][i][t][u][m] = res[0];
    dp[1][i][t][u][m] = res[1];
    return res[0];
}

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(C, -1, sizeof C);
    memset(dp[0], -1, sizeof dp[0]);
    cin >> S >> M;
    N = S.size();
    full = (1<<M) - 1;
    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        C[x] = i;
    }
    p10[0] = 1;
    for (int i = 1; i < N; ++i)
        p10[i] = mul(p10[i-1], 10);
}

int main() {
    init();
    dfs(0, 1, 0, 0);
    cout << dp[1][0][1][0][0] << '\n';
}
