// https://atcoder.jp/contests/abc210/tasks/abc210_d
// very very educational.
// we want to look for the best pair between current (i,j) and the sub-rectangle to the origin
// so, we use DP. let dp[i][j] be the minimum cost to reach (i,j).
// dp[i][j] = min( A[i][j], dp[i-1][j]+C, dp[i][j-1]+C )
// then the answer would be the minimum across all i,j of the following value:
// X[i][j] = min( dp[i-1][j] + C + A[i][j], dp[i][j-1] + C + A[i][j] )
// however, this only captures points where i1 < i2. So, we reverse A and run it again
// to grab pairs in the other diagonal direction.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

#define all(x) begin(x), end(x)

const int MXN = 1005;
const ll INF = 1e18+5;

int H, W;
ll C, dp[MXN][MXN];
vector<vector<ll>> A;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll ans = INF;
    cin >> H >> W >> C;
    A.assign(H+1, vector<ll>(W+1));
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
            cin >> A[i][j];

    for (int x : {0,1}) {
        fill( (ll*)dp, (ll*)dp+MXN*MXN, INF );
        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j) {
                ll v = A[i-x][j];
                ll abov = dp[i-1][j] + C;
                ll left = dp[i][j-1] + C;
                ans = min( {ans, abov+v, left+v} );
                dp[i][j] = min( {v, abov, left} );
            }
        reverse( all(A) );
    }
    cout << ans << '\n';
}
