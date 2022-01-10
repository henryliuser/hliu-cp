# https://codeforces.com/problemset/problem/1553/D
# important reminder to always consider working backwards
# clearly hard to do forwards, cuz you can start at any index
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    s, t = input(), input()
    ls, lt = len(s), len(t)
    if lt > ls: return "NO"

    i = j = 0
    while i < ls and j < lt:
        a, b = s[~i], t[~j]
        if a == b:
            i, j = i+1, j+1
        else:
            i += 2

    return "YES" if j == lt else "NO"

if __name__ == '__main__':
    q, = intput()
    for _ in range(q):
        print( solve() )

# def sim(s):
#     from collections import Counter
#     ans = set()
#     def dfs(i, cur):
#         if i >= len(s):
#             ans.add(''.join(cur))
#             return
#         c = cur[:]
#         if c: c.pop()
#         dfs(i+1, c)
#         dfs(i+1, cur + [s[i]])
#     dfs(0, [])
#     for q in sorted(ans):
#         print(q)
#     cnt = Counter(len(q) for q in ans)
#     for k,v in cnt.items():
#         print(k,v)
#
#
# sim("ababa")
# print('-'*50)
# sim("aaa")
# print('-'*50)
# sim("aababa")
