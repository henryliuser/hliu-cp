class Solution {
public:
    int N;
    long long MOD = 1e9 + 7;
    vector<vector<long long>> dp;
    long dfs(int i, int j, string& s) {
        if (i >  j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        long mid = dfs(i+1, j-1, s);
        char a = s[i], b = s[j];
        if (a != b) {
            dp[i][j] = dfs(i, j-1, s) + dfs(i+1, j, s) - mid;
        }
        else {
            int L = -1, R = -1;
            for (int z = i+1; z <= j-1; ++z)
                if (s[z] == a) {
                    L = z; break;
                }
            for (int z = j-1; z >= i+1; --z)
                if (s[z] == a) {
                    R = z; break;
                }
            if (L == -1) dp[i][j] = 2*mid + 2;
            else if (L == R) dp[i][j] = 2*mid + 1;
            else dp[i][j] = 2*mid - dfs(L+1, R-1, s);
        }
        dp[i][j] = (dp[i][j] + MOD) % MOD;
        return dp[i][j];
    }

    int countPalindromicSubsequences(string s) {
        N = s.size();
        dp.assign(N+1, vector<long long>(N+1, -1));
        return dfs(0, N-1, s) % MOD;
    }
};
