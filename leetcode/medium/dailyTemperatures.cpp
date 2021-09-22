class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int N = T.size();
        vector<int> stack, ans(N);
        for (int i = 0; i < N; ++i) {
            int t = T[i];
            while (!stack.empty() && t > T[stack.back()]) {
                int sb = stack.back();
                ans[sb] = i - sb;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};
