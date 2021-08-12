class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, string& s) {
        if (i >  j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        char a = s[i], b = s[j];
        if (a == b) dp[i][j] = 2 + dfs(i+1, j-1, s);
        else dp[i][j] = max(dfs(i+1, j, s), dfs(i, j-1, s));
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int N = s.size();
        dp.assign(N, vector<int>(N, -1));
        return dfs(0, N-1, s);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1));
        for (int i = N; i >= 1; --i) {
            for (int j = 1; j <= N; ++j) {
                if (i > j) dp[i][j] = 0;
                else if (i == j) dp[i][j] = 1;
                else if (s[i-1] == s[j-1])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[1][N];
    }
};
