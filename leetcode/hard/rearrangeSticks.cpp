class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long>> dp(n, vector<long>(k));
        for (int c = 0; c < k; c++)
            dp[0][c] = (c==0) ? 1 : 0;
        for (int r = 1; r < n; r++)
            dp[r][0] = dp[r-1][0] * r % 1000000007;

        for (int r = 1; r < n; r++) {
            for (int c = 1; c < k; c++) {
                dp[r][c] = (r * dp[r-1][c] + dp[r-1][c-1]) % 1000000007;
            }
        }
        return dp[n-1][k-1];
    }
};
