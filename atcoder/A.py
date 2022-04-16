import sys
from bisect import
# sys.setrecursionlimit(1<<20)
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    S, = input()
    for i in range(10):
        if str(i) not in S:
            print(i)
            exit()
