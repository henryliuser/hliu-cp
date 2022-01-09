# https://leetcode.com/contest/weekly-contest-275/problems/count-words-obtained-after-adding-a-letter/
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        cands = defaultdict(set)
        for sw in startWords:
            cands[len(sw)].add( ''.join(sorted(sw)) )

        def can(tw):
            m = len(tw)
            for i in range(m):
                d = tw[:i] + tw[i+1:]
                if d in cands[m-1]:
                    return 1
            return 0

        ans = 0
        for tw in targetWords:
            x = ''.join(sorted(tw))
            ans += can(x)
        return ans
