// O(N) time, O(1) memory
class Solution {
public:
    int numWays(int n, int k) {
        int one = k;
        int two = 0;
        int bad = 0;
        for (int i = 2; i <= n; ++i) {
            bad += two;
            int t = (one+two) * (k-1);
            two = one;
            one = t;
        }
        return one + two;
    }
};


// More intuitive, O(N) memory
class Solution {
public:
    int dp[3][51];
    // dp[c][i][j] = # ways for i fences, (c+1) consecutive, k colors
    int numWays(int n, int k) {
        dp[0][1] = k;
        for (int i = 2; i <= n; ++i) {
            int one = dp[0][i-1];
            int two = dp[1][i-1];
            int bad = dp[2][i-1];
            dp[2][i] = bad + two;
            dp[1][i] = one;
            dp[0][i] = (one + two) * (k-1);
        }
        return dp[0][n] + dp[1][n];
    }
};
