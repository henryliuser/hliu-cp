// https://leetcode.com/problems/two-city-scheduling/
// deceptive bounds

// n log n greedy
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size();
        sort(begin(A), end(A), [](const auto &a, const auto &b) {
           return (a[1]-a[0]) < (b[1]-b[0]);
        });

        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans += A[i][ (i < N/2) ];
        return ans;
    }
};

// bad N^3 dp
// class Solution {
// public:
//     int dp[205][205];  // i prefix, j go A, k last A?
//     int twoCitySchedCost(vector<vector<int>>& A) {
//         A.push_back( {0,0} );
//         int M = A.size();
//         int N = M / 2;
//         dp[0][0] = 0;
//         for (int i = 1; i <= M; ++i) {
//             int x = A[i-1][0];
//             dp[i][0] = A[i-1][1] + dp[i-1][0];
//             for (int j = 1; j <= min(i, N+1); ++j) {
//                 int cur = 0;
//                 int &r = dp[i][j] = dp[i][0];
//                 for (int k = i-1; k >= j-1; --k) {
//                     r = min(r, dp[k][j-1] + cur);
//                     if (k) cur += A[k-1][1];
//                 }
//                 r += x;
//             }
//         }
//         return dp[M][N+1];
//     }
// };
