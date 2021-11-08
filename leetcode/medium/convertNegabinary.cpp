class Solution {
public:
    string baseNeg2(int n) {
        string ans;
        if (n == 0) return "0";
        while (n) {
            int last = n & 1;
            ans.push_back(last + '0');
            n = -(n >> 1);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
