// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/
// honestly pretty nice problem
// obviously do prefix sum. to avoid overflow though, we need to
// store just the prime factorization of the numbers
// clearly the min(# of 2's and 5's) represents the number of trailing zeros
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimization ("unroll-loops")

using pf = array<int, 2>;
inline pf primeFactors(int x) {
    pf res = {0,0};
    while (x && x%2==0) ++res[0], x /= 2;
    while (x && x%5==0) ++res[1], x /= 5;
    return res;
}
inline pf operator*(pf a, pf b)  { return {a[0]+b[0], a[1]+b[1]}; }
inline pf operator/(pf a, pf b)  { return {a[0]-b[0], a[1]-b[1]}; }
inline pf operator*(pf a, int x) { return   a * primeFactors(x);  }

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& G) {
        int M = G.size();
        int N = G[0].size();
        vector<vector<pf>> A(M+1, vector<pf>(N+1));
        vector<vector<pf>> B(M+1, vector<pf>(N+1));
        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j) {
                int x = G[i-1][j-1];
                A[i][j] = A[i-1][j] * x;
                B[i][j] = B[i][j-1] * x;
            }
        int ans = 0;
        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j) {
                pf a = B[i][j] * (A[M][j] / A[i][j]);
                pf b = A[i][j] * (B[i][N] / B[i][j]);
                pf c = B[i][j] * A[i-1][j];
                pf d = (A[M][j] / A[i][j]) * (B[i][N] / B[i][j-1]);
                for (pf x : {a,b,c,d}) {
                    int res = min(x[0], x[1]);
                    ans = max(ans, res);
                }
            }
        return ans;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
