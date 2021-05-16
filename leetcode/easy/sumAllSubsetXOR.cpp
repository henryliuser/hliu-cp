class Solution {
public:

    int N;
    void dfs(int z, int curr, vector<int>& nums, int& ans) {
        if (z == N-1) {
            ans += curr;
            return;
        }
        z += 1;
        dfs(z, curr^nums[z], nums, ans); // take it
        dfs(z, curr, nums, ans); // or don't
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        N = nums.size();
        dfs(-1, 0, nums, ans);
        return ans;
    }
};
