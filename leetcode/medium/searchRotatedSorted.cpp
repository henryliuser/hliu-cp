class Solution {
public:

    int N;
    int pivot(vector<int>& nums) {
        int lo = 0, hi = N-1;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            int x = nums[mid], y = nums[hi];
            if (x > y) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    int search(vector<int>& nums, int target) {
        N = nums.size();
        int p = pivot(nums);
        int lo = 0, hi = N-1;
        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            int real = (mid + p) % N;
            int x = nums[real];
            if (target == x) return real;
            else if (target < x) {
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        return -1;
    }
};
