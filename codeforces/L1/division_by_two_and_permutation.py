# https://codeforces.com/contest/1624/problem/C
# a lesson in greed.
import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())
    req = set(range(1, N+1))
    can = set()
    for i,x in enumerate(A):
        if x in req: req.remove(x)
        else: can.add(i)
    allr = defaultdict(set)
    for i in can:
        c = A[i]
        while c:
            allr[i].add(c)
            c //= 2
    num = defaultdict(int)
    for r in req:
        for i in can:
            if r in allr[i]:
                num[r] += 1

    # very common greedy theme
    # process the most necessary ones first
    for r in sorted(req, key=lambda x: num[x]):
        for i in can:
            if r in allr[i]:
                can.remove(i)
                break
        else: return "NO"
    return "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
