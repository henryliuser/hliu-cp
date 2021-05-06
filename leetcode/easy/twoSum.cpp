#include <unordered_map>
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int z = 0; z < nums.size(); z++) {
        int n = nums[z];
        if (m.find(target - n) != m.end())
            return {z, m[target-n]};
        m[n] = z;
    }
} 
