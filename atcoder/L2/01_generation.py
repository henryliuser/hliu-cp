# https://atcoder.jp/contests/arc138/tasks/arc138_b
# sad :/
import sys
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    dq = deque( intput() )
    if dq[0] == 1: return "No"
    if N in [1,2]: return "Yes"

    f = 0  # flipped
    get = lambda b : dq[-b] ^ f
    pop = lambda b : (dq.pop() if b else dq.popleft()) ^ f
    while dq:
        if get(0) == 1: return "No"  # front is 1
        if get(1) == 0: pop(1)       #  back is 0
        else:                        #  back is 1, front is 0
            pop(0)
            f ^= 1

    return "Yes"

if __name__ == '__main__':
    print( solve() )
