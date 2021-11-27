import sys
from bisect import bisect_left
input = sys.stdin.readline
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        a, b, c = intput()
        am = a + c - 2*b
        print(1 if am%3 else 0)
