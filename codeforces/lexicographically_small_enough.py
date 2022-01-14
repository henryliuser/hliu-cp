import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

bit = []
def upd(x, i=0):
    while i < N:
        bit[i] += x
        i = i & -i

def solve():
    N, = intput()
    S, T = input(), input()




if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
