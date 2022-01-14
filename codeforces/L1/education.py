# https://codeforces.com/contest/1512/problem/F
# either commit to current or go next
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans = float('inf')
    N, C = intput()
    A = list(intput())
    B = list(intput())
    cdiv = lambda a,b : (a+b-1) // b

    cur = days = 0
    for i in range(N):
        dx = max(0, C - cur)
        ans = min(ans, days + cdiv(dx, A[i]))
        if i == N-1: continue
        dx = max(0, B[i] - cur)
        d = cdiv(dx, A[i])
        cur += d * A[i]
        cur -= B[i]
        days += d+1

    return ans


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
