# https://codeforces.com/contest/1651/problem/B
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    ans = [1]
    lim = int(1e9)
    for x in range(1, N):
        y = ans[-1] * 3
        if y <= lim:
            ans += [y]
        else:
            return []
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        s = solve()
        if not s: print("NO")
        else:
            print("YES")
            print(*s)
