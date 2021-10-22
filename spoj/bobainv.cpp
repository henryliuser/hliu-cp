// N^2 inversion range queries
// pretty instructive. DP on element pairs (sorta like palindrome),
// then run 2d prefix sums to answer queries on property

// had to submit in C to get AC lmao
#include <stdio.h>
int v[5001], dp[5001][5001];
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x = (i < j) ? (v[i-1] > v[j-1]) : 0;
            int a = dp[i-1][j];    // above
            int b = dp[i][j-1];    // behind
            int c = dp[i-1][j-1];  // double count
            dp[i][j] = x + a + b - c;
        }
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int L, R;
        scanf("%d %d", &L, &R);
        int all = dp[R][R];
        int top = dp[L-1][R];
        printf("%d\n", all - top);
    }
}
