# print(pow(7,2020,50))
from itertools import permutations

# p = permutations(range(1,9))
# ans = 0
# for x in p:
#     if x[0] > x[1] > x[2] > x[3] and x[3] < x[4] < x[5] < x[6] < x[7]:
#         print(x)
#         ans += 1
# print(ans)

# x = list(range(1,2021))
# while len(x) > 1:
#     print(x)
#     c, l = 0, len(x)
#     x = [x[y] for y in range(l) if y % 2 == 0]
#
# print(x[0])

for A in range(1,100):
    for B in range(1,100):
        for C in range(1,100):
            if A + 1/(B+1/C) == 38/9:
                print(A,B,C)
