import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())

    cnt = defaultdict(int)
    for x in A:
        if cnt[x] == 0:
            cnt[x] += 1
        else:
            cnt[-x] += 1
    return len(cnt)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
