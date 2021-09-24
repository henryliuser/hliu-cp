class Solution {
public:
    int N;
    stack<int> st;
    vector<int> aug, ans, nge;
    void process(stack<int>& st, int x, bool all) {
        while (!st.empty() && (all || x > aug[st.top()])) {
            int y = st.top();
            ans[y] = (all) ? -1 : x;
            st.pop();
        }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        N = nums.size();
        ans.resize(2*N);
        aug.resize(2*N);
        for (int i = 0; i < N; ++i) {
            aug[i] = nums[i];
            aug[i+N] = nums[i];
        }
        for (int i = 0; i < 2*N; ++i) {
            int x = aug[i];
            process(st, x, false);
            st.push(i);
        }
        process(st, INT_MAX, true);
        ans.resize(N);
        return ans;

    }
};
