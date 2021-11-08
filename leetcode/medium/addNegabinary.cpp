class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int N = arr1.size();
        int M = arr2.size();
        int carry = 0;
        for (int i=N-1, j=M-1; i+1 || j+1 || carry;) {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        int i = ans.size()-1;
        while (i+1 && ans[i--] == 0);
        ans.resize(i+2);
        reverse(begin(ans), end(ans));
        return ans;
    }
};
