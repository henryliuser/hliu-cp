class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int N = s.size();
        vector<vector<bool>> dp(2, vector<bool>(N+1));
        for (int r = N; r >= 1; --r) {
            int t = r % 2;
            for (int c = 1; c <= N; ++c) {
                if (r > c) dp[t][c] = false;
                else if (r == c) dp[t][c] = true;
                else if (s[r-1] == s[c-1]) {
                    if (c-r == 1) dp[t][c] = true;
                    else dp[t][c] = dp[!t][c-1];
                }
                else
                    dp[t][c] = false;
                ans += dp[t][c];
            }
        }
        return ans;
    }
};
