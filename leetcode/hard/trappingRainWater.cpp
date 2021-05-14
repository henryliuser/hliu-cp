class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int ans = 0;
        int left = 0, right = 0; // left boundary of current pocket
        int L = 0, R = N-1;
        while (L <= R) {
            int x = height[L];
            int y = height[R];
            if (x >= left)  left = x;
            else ans += left-x;
            if (y >= right)  right = y;
            else ans += right-y;
            if (x > y) R--;
            else L++;
        }
        return ans;
    }
};
