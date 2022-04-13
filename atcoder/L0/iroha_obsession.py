# https://atcoder.jp/contests/abc042/tasks/arc058_a
import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, K = intput()
    D = {*map(str,intput())}
    for x in range(N, 10*N+5):
        i = set(str(x)) & D
        if len(i) > 0: continue
        print(x)
        exit()
