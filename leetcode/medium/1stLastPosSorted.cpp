class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        int lo = 0, hi = N-1;
        vector<int> ans = {-1, -1};
        bool found = false;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int x = nums[mid];
            if (target <= x) {
                if (target == x) found = true;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        if (!found) return {-1, -1};
        ans[0] = lo;
        lo = 0, hi = N-1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int x = nums[mid];
            if (target >= x) lo = mid+1;
            else hi = mid - 1;
        }
        ans[1] = lo-1;
        return ans;
    }
};
