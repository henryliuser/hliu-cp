import sys
from collections import deque
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    S  = input()
    ans = deque([N])
    for i in range(N-1, -1, -1):
        if S[i] == 'R':
            ans.appendleft(i)
        else:
            ans.append(i)
    print(*ans)
