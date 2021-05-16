class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int N = nums.size();
        vector<int> dp(N, 1);
        for (int z = 1; z < N; z++) {
            int c = nums[z], mx = 0;
            for (int a = 0; a < z; a++)
                if (nums[a] < c) mx = max(mx, dp[a]);
            dp[z] = mx + 1;
            ans = max(ans, dp[z]);
        }
        return ans;
    }
};
