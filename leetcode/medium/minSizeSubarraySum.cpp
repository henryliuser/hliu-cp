class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 0;
        int i = 0, N = nums.size();
        int window = 0;
        for (int j = 0; j < N; ++j) {
            window += nums[j];
            while (window >= target) {
                if (!ans) ans = j-i+1;
                ans = min(ans, j-i+1);
                window -= nums[i++];
            }
        }
        return ans;
    }
};
