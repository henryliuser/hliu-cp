// nice problem. 2p + dp + binary search
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K; cin >> N >> K;
    vector<int> A(N), dp(N);
    for (int &x : A) cin >> x;
    sort(begin(A), end(A));

    int i = 0;  // 2P to calculate best with 1 case
    for (int j = 0; j < N; ++j) {
        int curr = A[j] - A[i];
        while (curr > K) curr = A[j] - A[++i];
        int pv = (j) ? dp[j-1] : 0;
        dp[j] = max(pv, j-i+1);
    }

    int ans = 0;  // binary search forward to calculate best starting at i
    for (i = 0; i < N; ++i) {
        int x = A[i];
        int idx = upper_bound(begin(A), end(A), x+K) - begin(A);
        int j = max(0, idx-1);
        int len = j-i+1;
        int pv = (i) ? dp[i-1] : 0;
        ans = max(ans, len + pv);
    }

    cout << ans << "\n";
}
