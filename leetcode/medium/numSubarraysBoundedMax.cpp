class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int N = A.size();
        int ans = 0, left = -1, right = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            result += right - left;
            // printf("%d %d %d %d\n", A[i], left, right, result);
        }
        return ans;
    }
};
