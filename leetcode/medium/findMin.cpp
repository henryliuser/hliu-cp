class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int lo = 0, hi = N-1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};
