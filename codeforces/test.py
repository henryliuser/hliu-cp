A = [81,75, 75, 93, 93, 87]
s = sum(A)
print(s)
n = 6
k = n*(n+1)//2
print(k)
B = (x-6 for x in A)
print(*B)


# from random import randint as rng
#
# def gen():
#     N = rng(3,15)
#     A = list(range(1,N+1))
#     c = N-1
#     P = []
#     for i in range(N):
#         j = rng(0,c)
#         x = A[j]
#         A[j], A[-1] = A[-1], A[j]
#         A.pop()
#         P += [x]
#         c -= 1
#     return N, P
#
# def sim(P, x):
#     cnt, res = 0, []
#     lo, hi = -1, 1e18
#     for i,z in enumerate(P):
#         if z > hi or z < lo: continue
#         res += ["HI"] if z > x else ["LO"]
#         if z > x: hi = min(hi, z)
#         else: lo = max(lo, z)
#     s = ''.join(res)
#     # print(s)
#     for i in range(len(s)-3):
#         if s[i:i+4] == "HILO":
#             cnt += 1
#     return cnt
#
# for x in range(0, 6):
#     print( sim([2,3,5,4,1], x) )
#
# # for t in range(10):
# #     N, P = gen()
# #     print('\n\n')
# #     print(N, *P)
# #     A = [sim(P,x) for x in range(N+1)]
# #     print(*A)
# #     print(*range(N+1))
