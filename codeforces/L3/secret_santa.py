# https://codeforces.com/contest/1530/problem/D
# nightmare problem for me.
import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = [0] + list(intput())
    ans = [-1] * (N+1)
    spare = []
    cnt = defaultdict(int)
    for x in A: cnt[x] += 1
    for i in range(1, N+1):
        if i not in cnt:
            spare += [i]

    K = N - len(spare)
    for i in range(1, N+1):
        if cnt[A[i]] > 1:
            x = spare.pop()
            if x == i:
                spare += [x]
                ans[i] = A[i]
            else:
                ans[i] = x
                cnt[A[i]] -= 1
        else:
            ans[i] = A[i]

    return K, ans[1:]

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        k, s = solve()
        print(k)
        print(*s)
