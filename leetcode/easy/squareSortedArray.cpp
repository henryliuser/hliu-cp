class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        int i = 0, j = N-1;
        while (i <= j) {
            int a = nums[i];
            int b = nums[j];
            if (abs(a) > abs(b))
                ans[--N] = a * nums[i++];
            else
                ans[--N] = b * nums[j--];
        }
        return ans;
    }
};
