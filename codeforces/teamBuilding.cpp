// https://codeforces.com/contest/1316/problem/E
// sort the people by decreasing A.
// let dp[i][m] = max score for prefix i, positions filled by mask m
// let c = i - 1 - popcnt(m)    -->    c = # of people not playing
// if (c < K) then init dp[i][m] = dp[i-1][m] + A[i]
// else init dp[i][m] = dp[i-1][m]
// if # of people not playing less than K, then we must add to audience
// if # of people not playing >= K, no point adding to audience (sorted by A)
// then chmax dp across all states:
// int z = m ^ (1 << j)
// if dp[i-1][z] is valid, chmax(dp[i][m], dp[i-1][z] + B[i][j])
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pl = pair<ll,int>;
#define popcnt(m) __builtin_popcount(m)
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

const ll inf = 1e18;

ll dp[100005][128];
void upd(ll &a, ll b, ll c = 0) {
    if (b == -1) return;
    a = max(a, b+c);
}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    int N, P, K;
    cin >> N >> P >> K;
    vector<pl> A( N+1, {inf,-1} );
    for (int i = 1; i <= N; ++i)
        cin >> A[i].F,
        A[i].S = i;
    vector<vector<ll>> B(N+1, vector<ll>(P));
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < P; ++j)
            cin >> B[i][j];

    sort( rall(A) );
    int p = (1 << P);
    dp[0][0] = 0;
    for(int i = 1; i <= N; ++i) {
        auto [x,q] = A[i];
        for (int m = 0; m < p; ++m) {
            int pc = popcnt(m);
            int c = i - 1 - pc;
            if (c < K) upd(dp[i][m], dp[i-1][m], x);
            else upd(dp[i][m], dp[i-1][m]);
            for (int j = 0; j < P; ++j) {
                bool taken = m & (1<<j);  // is position b taken?
                if (!taken) continue;
                int z = m ^ (1<<j);  // previous state mask
                upd(dp[i][m], dp[i-1][z], B[q][j]);
            }
        }
    }
    cout << dp[N][p-1] << '\n';
}
