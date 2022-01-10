# https://codeforces.com/problemset/problem/1598/B
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    M  = N // 2
    A  = [list(intput()) for _ in range(N)]
    for i in range(5):
        for j in range(i+1, 5):
            can = [0,0,0]  # [i, j, both]
            for x in A:
                if x[i] and x[j]: can[2] += 1
                elif x[i]: can[0] += 1
                elif x[j]: can[1] += 1
            if sum(can) != N: continue
            if can[0] > M or can[1] > M: continue
            dx = M - can[0]
            dy = M - can[1]
            if dx + dy == can[2]: return "YES"
    return "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
