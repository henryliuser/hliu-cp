class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        vector<int> dp(N);
        for (int x : nums) {
            int lo = 0, hi = ans;
            while (lo < hi) {
                int mid = lo + (hi-lo) / 2;
                if (dp[mid] < x) lo = mid+1;
                else hi = mid;
            }
            dp[lo] = x;
            if (lo == ans) ans++;
        }
        return ans;
    }

    // int lengthOfLIS(vector<int>& nums) {
    //     int ans = 1;
    //     int N = nums.size();
    //     vector<int> dp(N, 1);
    //     for (int i = 1; i < N; ++i) {
    //         int c = nums[i], mx = 0;
    //         for (int j = 0; j < i; ++j) {
    //             if (nums[j] < c)
    //                 mx = max(mx, dp[j]);
    //         }
    //         dp[i] = mx + 1;
    //         ans = max(ans, dp[i]);
    //     }
    //     // for (auto d : dp) printf("%d ", d);
    //     return ans;
    // }
};
