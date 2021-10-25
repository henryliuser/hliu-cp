#include <bits/stdc++.h>
using namespace std;

int A[249];
int dp[249][249];

int main() {
    int ans = 0;
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int N; cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i+len <= N; ++i) {
            if (len == 1) {
                dp[i][i] = A[i];
                continue;
            }
            int k = i+len-1;
            int x = -1;
            for (int j = i; j < k; ++j) {
                int L = dp[i][j];
                int R = dp[j+1][k];
                if (L == -1 || R == -1) continue;
                if (L == R) x = max(x, dp[i][j]+1);
            }
            dp[i][k] = x;
            ans = max(ans, x);
        }
    }

    cout << ans << endl;
}
