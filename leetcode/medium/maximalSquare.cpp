class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int ans = 0;
        int M = A.size();
        int N = A[0].size();
        vector<vector<int>> dp(2, vector<int>(N+1));
        for (int r = 1; r <= M; ++r) {
            int t = r % 2;
            for (int c = 1; c <= N; ++c) {
                if (A[r-1][c-1] == '0') { dp[t][c] = 0; continue; }
                int W = dp[t][c-1];
                int NW = dp[!t][c-1];
                int N = dp[!t][c];
                if (W == NW && W == N)  dp[t][c] = W+1;
                else dp[t][c] = min({W, NW, N}) + 1;
                ans = max(ans, dp[t][c]);
            }
        }
        return ans * ans;
    }
};
