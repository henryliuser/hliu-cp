class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window + hash, O(N) time, O(M) space where m is the ans
        ls, seen = len(s), set()
        fast, slow = 0, 0
        ans = 0
        while fast < ls:
            char = s[fast]
            if char not in seen:
                seen.add(char)
                fast += 1
                m = max(ans, len(seen))
                if m > ans:
                    ans = max(ans, len(seen))
                    st = s[slow:fast]
            else:
                seen.remove(s[slow])
                slow += 1
        ans = max(ans, len(seen))
        print(st)
        return ans

        # if you need to return the substr
        ls, seen = len(s), set()
        fast, slow = 0, 0
        ans = ""
        while fast < ls:
            char = s[fast]
            if char not in seen:
                seen.add(char)
                fast += 1
                if len(seen) > len(ans):
                    ans = s[slow:fast]
            else:
                seen.remove(s[slow])
                slow += 1
        return ans


        # hashing O(N^2) time, TLE
        ls, ans = len(s), 0
        for i in range(ls):
            seen = set()
            for char in s[i:]:
                if char in seen:
                    ans = max(ans, len(seen))
                    seen = {char}
                else: seen.add(char)
            ans = max(ans, len(seen))
        return ans
