using ll = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ll ans = 0;
        int m = points.size();
        int n = points[0].size();
        vector<vector<ll>> dp(3, vector<ll>(n)); // [suf, pre, curr]
        for (int i = 0; i < n; ++i) {
            dp[2][i] = points[0][i];
            dp[0][i] = points[0][i] - i;
            dp[1][i] = points[0][i] - (n-i-1);
            ans = max(ans, dp[2][i]);
        }

        for (int r = 1; r < m; ++r) {
            for (int i = 1; i < n; ++i) {  // compute prefix/suffix max
                dp[0][n-i-1] = max(dp[0][n-i-1], dp[0][n-i]);
                dp[1][i] = max(dp[1][i], dp[1][i-1]);
            }
            for (int c = 0; c < n; ++c) {  // take best
                ll L = dp[1][c] + n-c-1;
                ll R = dp[0][c] + c;
                dp[2][c] = (ll)points[r][c] + max(L,R);
                ans = max(ans, dp[2][c]);
            }
            for (int i = 0; i < n; ++i) {  // compute weighted values
                dp[0][i] = dp[2][i] - i;
                dp[1][i] = dp[2][i] - (n-i-1);
            }
        }
        return ans;
    }
};
