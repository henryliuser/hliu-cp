# https://atcoder.jp/contests/abc236/tasks/abc236_d
# just backtrack. not sure how so few people solved it
import sys
from bisect import bisect_left
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def dfs(have, seen, cur):
    global ans
    if len(have) == 0:
        ans = max(ans, cur)
        return

    a = have.pop()
    seen.add(a)
    new = set(have)
    for b in new:
        have.remove(b)
        seen.add(b)
        i,j = sorted((a,b))
        c = (cur ^ A[i][j-i-1])
        dfs(have, seen, c)
        have.add(b)
        seen.remove(b)
    seen.remove(a)
    have.add(a)

if __name__ == '__main__':
    ans = 0
    N, = intput()
    A = [list(intput()) for _ in range(2*N-1)]
    have = set(range(2*N))
    seen = set()
    dfs(have, seen, 0)
    print(ans)
