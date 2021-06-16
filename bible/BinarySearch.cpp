int binarySearch(vector<int>& nums, int target) {
    int L = 0, R = nums.size()-1; // or N
    while (L < R) {
        int M = L + (R - L) / 2; // prevent overflow;
        if (nums[M] < target)      L = M+1;
        else if (nums[M] > target) R = M-1;
        else return M;
    }
    return -1;
}
