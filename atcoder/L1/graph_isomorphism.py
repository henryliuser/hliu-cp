# https://atcoder.jp/contests/abc232/tasks/abc232_c
import sys
from itertools import permutations
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, M = intput()
    adj = [defaultdict(set) for _ in range(2)]
    for i in range(2*M):
        a, b = intput()
        adj[i//M][a-1].add(b-1)
        adj[i//M][b-1].add(a-1)

    def check(p):
        for i in range(N):
            for j in range(i+1,N):
                tHas = j in adj[0][i]
                aHas = p[j] in adj[1][ p[i] ]
                if aHas != tHas:
                    return False
        return True

    P = permutations(range(N))
    ans = any(map(check, P))
    return "Yes" if ans else "No"

if __name__ == '__main__':
    print( solve() )
