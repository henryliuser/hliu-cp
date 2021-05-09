class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        int i = 0, j = N-1;
        int c = N-1;
        vector<int> ans(N);
        while (i <= j) {
            long a = nums[i];
            long b = nums[j];
            if (abs(a) > abs(b)) ans[c--] = a * nums[i++];
            else ans[c--] = b * nums[j--];
        }
        return ans;
    }
};
