# super clean, no need for DP or BST.
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        ans = m = 0  # m represents max value of finished event so far
        N = len(events)
        proc = []
        for s,e,v in events:
            proc.append( (s, True, v) )  # time, is_start, val
            proc.append( (e+1, False, v) )  # use e+1 (inclusive)
        proc.sort()  # sort by time

        for time, is_start, val in proc:
            if is_start:
                ans = max(ans, m+val)
            else:
                m = max(m, val)
        return ans
