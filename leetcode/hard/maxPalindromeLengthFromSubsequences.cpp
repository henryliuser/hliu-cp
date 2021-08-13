class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int ans = 0;
        int M = word1.size();
        int N = word2.size();
        int L = M + N;
        string w3 = word1 + word2;
        vector<vector<int>> dp(2, vector<int>(L+1));
        for (int i = L; i >= 1; --i) {
            int t = i % 2;
            for (int j = 1; j <= L; ++j) {
                if (i > j) dp[t][j] = 0;
                else if (i == j) dp[t][j] = 1;
                else if (w3[i-1] == w3[j-1]) {
                    dp[t][j] = 2 + dp[!t][j-1];
                    if (i-1 < M && j-1 >= M)
                        ans = max(ans, dp[t][j]);
                }
                else dp[t][j] = max(dp[!t][j], dp[t][j-1]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int M, N;
    vector<vector<int>> dp;
    int ans = 0;
    int dfs(int i, int j, string& s) {
        // returns LPS of s[i:j]
        // w1/w2 -> takes from word1/word2
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        bool w1 = i < M, w2 = j >= M;
        if (s[i] == s[j]) {
            dp[i][j] = 2 + dfs(i+1, j-1, s);
            if (w1 && w2)
                ans = max(ans, dp[i][j]);
        }
        else {
            dp[i][j] = max(dfs(i+1, j, s), dfs(i, j-1, s));
        }
        return dp[i][j];
    }

    int longestPalindrome(string word1, string word2) {
        M = word1.size();
        N = word2.size();
        dp.assign(M+N, vector<int>(M+N, -1));
        string w3 = word1 + word2;
        dfs(0, M+N-1, w3);
        return ans;
    }
};
