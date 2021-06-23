class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        def toM(s):
            H, M = map(int, s.split(":"))
            return H*60 + M

        start, end = map(toM, (startTime, finishTime))
        if 0 <= end - start < 15: return 0
        start = ceil(start/15) * 15
        end = end//15 * 15
        if end < start: end += 1440
        return (end-start) // 15
