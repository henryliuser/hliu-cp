class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int ans = 0;
        int M = A.size();
        int N = A[0].size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int r = 1; r <= M; ++r) {
            for (int c = 1; c <= N; ++c) {
                if (A[r-1][c-1] == '0') continue;
                int W = dp[r][c-1];
                int NW = dp[r-1][c-1];
                int N = dp[r-1][c];
                if (W == NW && W == N)  dp[r][c] = W+1;
                else dp[r][c] = min({W, NW, N}) + 1;
                ans = max(ans, dp[r][c]);
            }
        }
        return ans * ans;
    }
};
