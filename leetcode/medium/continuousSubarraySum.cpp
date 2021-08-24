class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int N = nums.size();
        unordered_map<int, int> seen = {{0, -1}};
        for (int z = 0; z < N; ++z) {
            sum = (sum + nums[z]) % k;
            if (seen.count(sum)) {
                if (seen[sum] < z-1)
                    return true;
            }
            else seen[sum] = z;
        }
        return false;
    }
};
