import sys
from functools import *
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    Q = 998244353
    X, = intput()
    @lru_cache(None)
    def dfs(x):
        if x <= 3: return x
        return dfs(x//2) * dfs((x+1)//2) % Q

    print(dfs(X) % Q)
