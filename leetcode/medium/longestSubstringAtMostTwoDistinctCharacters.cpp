class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int N = s.size();
        int i = 0, ans = 0;
        unordered_map<int, int> curr;
        for (int j = 0; j < N; ++j) {
            ++curr[ s[j] ];
            while (curr.size() > 2)
                if (--curr[ s[i++] ] <= 0)
                    curr.erase(s[i-1]);
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
