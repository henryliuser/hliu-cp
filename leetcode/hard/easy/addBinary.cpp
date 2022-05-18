class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int N = a.size(), M = b.size();
        int i = N-1, j = M-1;
        bool carry = false;
        while (i >= 0 || j >= 0 || carry) {
            int amt = carry;
            if (i >= 0) amt += a[i]-'0';
            if (j >= 0) amt += b[j]-'0';
            ans.push_back((amt % 2) + '0');
            carry = (amt > 1);
            --i; --j;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
