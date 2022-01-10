# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        cur = 0
        for i in range(1, n):
            if knows(cur, i) and not knows(i, cur):
                cur = i
        for i in range(n):
            if i == cur: continue
            if not knows(i, cur) or knows(cur, i):
                return -1
        return cur
