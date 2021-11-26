class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        int N = A.size();
        vector<int> dp, ans(N);
        for (int i = 0; i < N; ++i) {
            int x = A[i];
            int j = upper_bound(begin(dp), end(dp), x) - begin(dp);
            ans[i] = j+1;
            if (j == dp.size()) dp.push_back(x);
            else dp[j] = x;
        }
        return ans;
    }
};
