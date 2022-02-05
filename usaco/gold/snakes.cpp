// http://www.usaco.org/index.php?page=viewproblem2&cpid=945
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

ll dp[401][401];
// dp[k][i] = best from 0..i with K switches

// A     [7 9 8  2  3  2]
// K=0:  [0 2 3 10 16 23]

void chmax(ll &x, ll y) { x = max(x,y); }
void chmin(ll &x, ll y) { x = min(x,y); }

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    for (int i = 0; i < 401*401; ++i)
        dp[0][i] = INF;
}

int main() {
    init();
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    ll mx = 0, pre = 0;
    for (int i = 0; i < N; ++i) {
        pre += A[i];
        chmax(mx, A[i]);
        chmin(dp[0][i], mx * (i+1) - pre);
    }

    for (int k = 1; k <= K; ++k) {
        for (int i = k; i < N; ++i) {
            auto &r = dp[k][i];
            r = dp[k-1][i];
            mx = pre = A[i];
            for (int j = i-1; j >= 0; --j) {  // j = prev switch point
                ll len = i-j;
                chmin(r, dp[k-1][j] + mx*len-pre);
                pre += A[j];
                chmax(mx, A[j]);
            }
        }
    }
    ll ans = INF;
    for (int k = 0; k <= K; ++k)
        chmin(ans, dp[k][N-1]);
    cout << ans << '\n';
}
