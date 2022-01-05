"""
N = 5
FLOOR SUM
5 2 1
1 + 1 + 1 + 2 + 5

CEIL SUM
1 2 3 5
5 + 3 + 2 + 2 + 1
"""
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()

    s = set()  # unique denominators
    for x in range(1, N+1):
        if x*x > N: break
        s.add(N // x)
        s.add(x)

    ans = N
    uqd = sorted(s, reverse=True)
    for i in range(1, len(uqd)):
        l, r = uqd[i], uqd[i-1]
        cnt = r-l
        ans += cnt * (N // r)
    print(ans)
