import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    s = input()
    N = len(s)
    pre = [0] * (N+1)
    for i in range(N):
        pre[i+1] = int(s[i]) + pre[i]

    ans, carry = [], 0
    for i in range(N, 0, -1):
        x = carry + pre[i]
        carry = x // 10
        ans += [str(x % 10)]
    if carry: ans += ['1']

    print( ''.join(ans[::-1]) )


# This solves a slightly harder problem.
# everything is the same except it's sum from 0 <= k <= m
#
# def solve(s, m):
#     N = len(s)
#     pre = [0] * (N+1)
#     for i in range(N):
#         pre[i+1] = int(s[i]) + pre[i]
#
#     ans, carry = [], 0
#     for i in range(N, 0, -1):
#         x = carry + pre[i] - pre[max(0, i-m-1)]
#         carry = x // 10
#         ans += [str(x % 10)]
#     if carry: ans += ['1']
#
#     return ''.join(ans[::-1]).lstrip('0')
