class Solution {
public:
    // O(N^3), pretty tough to derive.
    // dp[i][j] = max coins if you only burst subarray i:j
    // In the CONTEXT of the entire array.
    int maxCoins(vector<int>& A) {
        int N = A.size();
        A.insert(A.begin(), 1);
        A.push_back(1);
        vector<vector<int>> dp(N+2, vector<int>(N+2));
        for (int i = N; i >= 1; --i) {
            for (int j = i; j <= N; ++j) {
                for (int k = i; k <= j; ++k) {
                    int left  = dp[i][k-1];
                    int right = dp[k+1][j];
                    int last  = A[i-1] * A[k] * A[j+1];
                    int x = left + right + last;
                    dp[i][j] = max(dp[i][j], x);
                }
            }
        }
        return dp[1][N];
    }
};
