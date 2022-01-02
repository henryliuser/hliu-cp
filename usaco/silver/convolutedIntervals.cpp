// http://usaco.org/index.php?page=viewproblem2&cpid=1160
// nice question. notice that if you run N^2, each pair (i,j)
// has a contiguous section where it contributes to the answer.
// run prefix sums, and only iterate on 5k unique values instead
// unordered_map TLE's on case 3/20 somehow.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt[2][5001];  // 0:A, 1:B
int main() {
    memset(cnt, 0, sizeof cnt);
    int N, M; cin >> N >> M;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        ++cnt[0][ A[i] ], ++cnt[1][ B[i] ];
    }
    vector<ll> sum(2*M+2);  // prefix sum of win ranges
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= M; ++j) {
            sum[ i+j ] += cnt[0][i] * cnt[0][j];
            sum[i+j+1] -= cnt[1][i] * cnt[1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 2*M; ++i) {
        ans += sum[i];
        cout << ans << "\n";
    }
}
