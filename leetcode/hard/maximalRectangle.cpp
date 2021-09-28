class Solution {
public:
    int M, N;
    int maxAreaHistogram(vector<int>& heights) {
        int ans = 0;
        stack<int> stn, stp;
        vector<int> nse(N, -1), pse(N, -1);
        for (int i = 0; i < N; ++i) {
            int x = heights[i];
            int y = heights[N-i-1];
            while (!stn.empty() && x < heights[stn.top()]) {
                int p = stn.top();
                nse[p] = i;
                stn.pop();
            }
            while (!stp.empty() && y < heights[stp.top()]) {
                int q = stp.top();
                pse[q] = N-i-1;
                stp.pop();
            }
            stn.push(i);
            stp.push(N-i-1);
        }
        for (int i = 0; i < N; ++i) {
            int next = nse[i]-1;
            int prev = pse[i]+1;
            if (next == -2) next = N-1;
            int area = heights[i] * (next-prev+1);
            ans = max(ans, area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        M = matrix.size();
        if (!M) return 0;
        N = matrix[0].size();
        vector<vector<int>> dp(M+1, vector<int>(N));
        for (int i = 1; i <= M; ++i) {
            for (int j = 0; j < N; ++j) {
                char c = matrix[i-1][j];
                if (c == '1') dp[i][j] = 1 + dp[i-1][j];
                if (c == '0') dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= M; ++i) {
            ans = max( ans, maxAreaHistogram(dp[i]) );
        }
        return ans;
    }
};

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
