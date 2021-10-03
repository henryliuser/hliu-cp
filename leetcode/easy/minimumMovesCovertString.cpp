class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == 'X') {
                ++ans;
                i += 2;
            }
        }
        return ans;
    }
};
