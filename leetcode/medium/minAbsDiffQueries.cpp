class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), Q = queries.size();
        vector<int> ans(Q);
        vector<vector<int>> dp(N+1, vector<int>(101, 0));
        for (int r = 1; r <= N; ++r) {
            for (int c = 1; c <= 100; ++c)
                dp[r][c] = dp[r-1][c];
            dp[r][nums[r-1]]++;
        }

        for (int q = 0; q < Q; ++q) {
            int L = queries[q][0];
            int R = queries[q][1] + 1;
            auto& a = dp[L], b = dp[R];
            ans[q] = INT_MAX;
            vector<int> newNums;
            for (int z = 1; z <= 100; ++z)
                if (a[z] != b[z]) newNums.push_back(z);
            if (newNums.size() == 1)
                ans[q] = abs(nums[R-1] - nums[L]);
            for (int n = 1; n < newNums.size(); ++n)
                ans[q] = min(ans[q], newNums[n]-newNums[n-1]);

            if (!ans[q]) ans[q]--;
        }
        return ans;
    }
};
