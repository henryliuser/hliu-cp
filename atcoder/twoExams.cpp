#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 998244353;

ll dp[2][301][301] = {};
// dp[i][k][m] = # of valid choices in first i people of length k, with min m

inline void add(ll &x, ll y) { ((x+=y)>=Q) ? x-=Q : x; }

int main() {
    int N, K; cin >> N >> K;
    vector<int> P(N), Q(N);
    for (int &x : P) cin >> x;
    for (int &x : Q) cin >> x;

    vector<int> A(N);  // sort (p,q) by p
    for (int i = 0; i < N; ++i)
        A[ P[i]-1 ] = Q[i]-1;

    dp[0][0][N] = 1;   // N = inf = no minimum yet
    for (int i = 0; i < N; ++i) {
        memset(dp[1], 0, sizeof dp[1]);
        for (int k = 0; k <= K; ++k) {
            for (int m = 0; m <= N; ++m) {
                if (k < K && A[i] < m)  // is valid  (>, <)
                    add(dp[1][k+1][m], dp[0][k][m]);  // (<i, m), (i, <m)

                int nm = min(m, A[i]);
                add(dp[1][k][nm], dp[0][k][m]);
            }
        }
        swap(dp[0], dp[1]);
    }

    ll ans = 0;
    for (int m = 0; m <= N; ++m)
        add(ans, dp[0][K][m]);
    cout << ans << '\n';
}
