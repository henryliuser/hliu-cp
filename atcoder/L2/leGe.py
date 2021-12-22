# https://atcoder.jp/contests/agc040/tasks/agc040_a
# important realization here is that segments don't necessarily depend on
# all other segments. Only constrained by left and right neighbors.
# can see this because '><' pattern always results in a 0, so anything to the
# left of this is not relevant for the current index.

# also a nice trick to compute the max consecutive left/right per element
# I think i would've merged angle brackets into integer counts and try some
# math or binary search to accomplish the same thing.
# kenkoooo calls this 400 rating lmao :(

# solution:
# ans for each index is:
# let L = # of consecutive '<' with index < i
# let R = # of consecutive '>' with index >= i
# ans[i] = max(L, R)
# compute it backwards for O(N)
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    S = input()
    N = len(S)
    ans = [0] * (N+1)
    for i in range(N):
        if S[i] == '<':
            ans[i+1] = max(ans[i+1], ans[i] + 1)
    for i in range(N-1, -1, -1):
        if S[i] == '>':
            ans[i] = max(ans[i], ans[i+1] + 1)  # asymmetric indexing

    print( sum(ans) )


# This is WA. unsure why, but the editorial approach makes sense.
# if __name__ == '__main__':
#     S = list(input()) + ['?']
#     N = len(S)
#     c, ge = 0, []
#     ans = [0]
#
#     stk = [S[0], 1]
#     for i in range(1, N):
#         if S[i] != S[i-1]:
#             if stk[0] == '>':
#                 ge.append(stk[1])
#             stk = [S[i], 1]
#         else:
#             stk[1] += 1
#
#     for i in range(1, N):
#         a, b = S[i-1], S[i]
#         v = (1 if a == '<' else -1)
#         x = ans[-1] + v
#         if a == '<' and b == '>':
#             x = ge[c]
#             c += 1
#         if a == '>' and b == '<':
#             x = 0
#         ans.append(x)
#
#     for i in range(1, N):
#         a, b = S[i-1], S[i]
#         v = (1 if a == '<' else -1)
#         x = ans[i-1] + v
#         if a == '<' and b == '>':
#             ans[i] = max(ans[i], x)
#
#     print( sum(ans) )
