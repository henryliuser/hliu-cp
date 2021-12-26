import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, K = intput()
    A = list(intput())
    cnt = defaultdict(int)

    cnt[0] = 1
    ans = s = 0
    for i in range(N):
        s += A[i]
        ans += cnt[s-K]
        cnt[s] += 1
    print(ans)
