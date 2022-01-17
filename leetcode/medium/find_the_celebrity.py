# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

# 2491 ms standard
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

# 2566 ms randomized
class Solution:
    def findCelebrity(self, n: int) -> int:
        order = list(range(n))
        random.shuffle(order)
        for i in range(n):
            for j in order:
                if j == i: continue
                if knows(i,j): break
                if not knows(j,i): break
            else:
                return i
        return -1
