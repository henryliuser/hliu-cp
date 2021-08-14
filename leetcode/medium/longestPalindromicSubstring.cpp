// my O(N^2) bottom up. Bad.
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<bool>> dp(2, vector<bool>(N));
        int len = 0;
        int ax = -1;
        for (int r = N-1; r >= 0; --r) {
            int t = r % 2;
            for (int c = r; c < N; ++c) {
                if (r == c) dp[t][c] = true;
                else if (s[r] == s[c]) {
                    if (c-r == 1) dp[t][c] = true;
                    else dp[t][c] = dp[!t][c-1];
                }
                else dp[t][c] = false;
                if (dp[t][c] && c-r+1 > len) {
                    len = c-r+1;
                    ax = r;
                }
            }
        }
        return s.substr(ax, len);
    }
};


// cracked solution 4ms LC: @mufeng321. no idea how it works yet.
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        size_t start = 0, len = 0;
        for (size_t i = 0; i < s.length() && s.length() - i > len / 2;) {
            size_t left = i, right;
            for (right = i + 1; right < s.length() && s[right] == s[right - 1]; right++) {}
            for (i = right--; left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1]; left--, right++) {}
            auto _len = right - left + 1;
            if (_len > len) {
                start = left;
                len = _len;
            }
        }
        return s.substr(start, len);
    }
};


// also cracked @hh1985. 8ms
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
