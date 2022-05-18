// O(N)
class Solution {
public:
    int tribonacci(int n) {
        int dp[4] = {0, 1, 1, 2};
        if (n < 4) return dp[n];
        for (int i = 3; i <= n; ++i) {
            dp[3] = dp[0] + dp[1] + dp[2];
            for (int j = 0; j < 3; ++j)
                dp[j] = dp[j+1];
        }
        return dp[3];
    }
};

// O(log N) matrix exponentiation, not my solution
// credit: @dangledangkhoa on leetcode
class Solution {
private:
    vector<vector<int>> matrixMul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
        vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
        for(int i=0; i<A.size(); ++i)
            for(int k=0; k<B.size(); ++k)
                for(int j=0; j<B[0].size();++j) {
                    C[i][j] += (A[i][k] * B[k][j]);
                }
        return C;
    }
    vector<vector<int>> matrixPow(const vector<vector<int>> &A, int k) {
        if(k == 0) {
            vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
            for(int i=0; i < A.size(); ++i) C[i][i] = 1;
            return C;
        }
        if(k == 1) return A;

        vector<vector<int>> C = matrixPow(A, k/2);
        C = matrixMul(C, C);
        if(k%2 == 1) return matrixMul(C,A);
        return C;
    }
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n==1 || n==2) return 1;

        int f_0 = 0;
        int f_1 = 1;
        int f_2 = 1;

        vector<vector<int>> C = matrixPow({
            {1,1,1},
            {1,0,0},
            {0,1,0}
        }, n-2);
        return matrixMul(C, {
            {f_2},
            {f_1},
            {f_0}
        })[0][0];
    }
};
