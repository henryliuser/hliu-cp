// O(MN^2) time, O(N) space
// dp[r][c] = # of consecutives ones above mtx[r-1][c-1]
// at each (r,c) scan left and update the best ans
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mtx) {
        int ans = 0;
        int M = mtx.size();
        if (!M) return 0;
        int N = mtx[0].size();
        vector<vector<int>> dp(2, vector<int>(N+1));
        for (int r = 1; r <= M; ++r) {
            int t = r % 2;
            for (int c = 1; c <= N; ++c) {
                if (mtx[r-1][c-1] == '0') { dp[t][c] = 0; continue; }
                dp[t][c] = 1 + dp[!t][c];
                int minH = dp[t][c];
                for (int x = c; x > 0; --x) {
                    if (mtx[r-1][x-1] != '1') break;
                    minH = min(minH, dp[t][x]);
                    int width = c-x+1;
                    ans = max(ans, width*minH);
                }
            }
        }
        return ans;
    }
};
