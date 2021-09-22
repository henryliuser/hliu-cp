class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int M = nums1.size();
        int N = nums2.size();
        vector<int> ans(M), nge(N);
        unordered_map<int, int> idx;
        for (int i = 0; i < N; ++i)
            idx[nums2[i]] = i;

        for (int i = 0; i < N; ++i) {
            int x = nums2[i];
            while (!st.empty() && x > nums2[st.top()]) {
                int y = st.top();
                nge[y] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < M; ++i) {
            int x = nums1[i];
            int ngeIdx = nge[idx[x]];
            ans[i] = (ngeIdx != -1) ? nums2[ngeIdx] : -1;
        }
        return ans;
    }
};
