import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())


def solve():
    N, = intput()
    A = list(intput())
    B = [[],[]]
    for x in A:
        B[x%2] += [x]
    if B[0] != sorted(B[0]): return "No"
    if B[1] != sorted(B[1]): return "No"
    return "Yes"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print(solve())
