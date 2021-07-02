class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> dp(N, {1, -1});
        sort(nums.begin(), nums.end());
        int idx = 0, m = 0;
        for (int i = 0; i < N; ++i) {
            int mx = 0;
            int x = nums[i];
            for (int j = 0; j < i; ++j) {
                int y = nums[j];
                if (x % y == 0) {
                    if (dp[j].first+1 > mx) {
                        mx = dp[j].first+1;
                        dp[i].second = j;
                    }
                }
            }
            dp[i].first = mx;
            if (dp[i].first > m) {
                m = dp[i].first;
                idx = i;
            }
        }
        vector<int> ans;
        while (true) {
            ans.push_back(nums[idx]);
            idx = dp[idx].second;
            if (idx == -1) break;
        }
        return ans;
    }
};
