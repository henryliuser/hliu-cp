class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int L = 0, R = 0;
        int N = nums.size();
        int ans = 0;
        map<int, int> mp; // frequency of nums in window
        mp[nums[0]]++;
        while (L < N) {
            int maxi = mp.rbegin()->first;
            int mini = mp.begin()->first;
            int diff = maxi - mini;
            if (diff <= limit) {
                ans = max(ans, R-L+1);
                if (R < N-1) mp[nums[++R]]++;
                else break;
            }
            else {
                mp[nums[L++]]--;
                if (!mp[nums[L-1]])
                    mp.erase(nums[L-1]);
            }
        }
        return ans;
    }
};
