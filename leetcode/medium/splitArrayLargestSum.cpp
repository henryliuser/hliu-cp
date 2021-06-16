class Solution {
public:
    int N;
    bool check(vector<int>& nums, int guess, int m) {
        int curr = 0, count = 1; // exact same as shipping container
        for (int& n : nums) {
            if (n > guess) return false;
            curr += n;
            if (curr > guess) {
                curr = n;
                count++;
            }
        }
        return count <= m;
        // <= because you can always split it if it's less than m
    }

    int splitArray(vector<int>& nums, int m) {
        N = nums.size();
        int lo = 0;
        int hi = 0;
        for (int& n : nums) hi += n;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (check(nums, mid, m)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
