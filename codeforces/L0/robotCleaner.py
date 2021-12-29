# https://codeforces.com/contest/1623/problem/A
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, M, rb, cb, rd, cd = intput()
    rb, cb, rd, cd = rb-1, cb-1, rd-1, cd-1
    t = 0
    dr = dc = 1
    while 1:
        if rb == rd or cb == cd:
            return ta
        x = rb + dr
        if x < 0 or x >= N:
            x = rb - dr
            dr *= -1
        y = cb + dc
        if y < 0 or y >= M:
            y = cb - dc
            dc *= -1
        rb, cb = x, y
        t += 1

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
