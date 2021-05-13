class Solution {
public:

    int N;
    int dfs(int z, vector<short>& seen, vector<int>& nums) {
        if (seen[z] != -1) return seen[z];
        int n = nums[z];
        int cash = n;
        if (z+1 < N) cash = max(cash, dfs(z+1, seen, nums));
        if (z+2 < N) cash = max(cash, n+dfs(z+2, seen, nums));
        seen[z] = cash;
        return cash;
    }
    
    int rob(vector<int>& nums) {
        N = nums.size();
        vector<short> dp(N, -1);
        return dfs(0, dp, nums);
    }

    // O(1) space psychopath solution

    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     int a = 0, b = 0;
    //
    //     for (int i=0; i<n; i++) {
    //         if (i%2==0)
    //             a = max(a+nums[i], b);
    //         else
    //             b = max(a, b+nums[i]);
    //     }
    //
    //     return max(a, b);
    // }
};
