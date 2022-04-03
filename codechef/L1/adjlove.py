# https://www.codechef.com/problems/ADJLOVE
# got stuck on lame edge case :/
import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]
    B = [[], []]
    for x in A:
        B[x%2] += [x]

    e = len(B[0])
    o = len(B[1])
    if o in [0,1] or (e == 0 and o % 2):
        return print(-1)

    ans = []
    if o % 2:
        for i in range(o-1):
            ans += [ B[1].pop() ]
        ans += B[0] + B[1]
    else:
        ans = B[1] + B[0]

    return print(*ans)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
