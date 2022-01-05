# https://codeforces.com/problemset/problem/1612/D
# think of the tree, eliminate redundant computations
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    A, B, X = intput()
    def dfs(a, b):
        if a < b: a,b = b,a
        if X > a or a == 0 or b == 0: return 0
        if (a-X) % b == 0: return 1
        return dfs(b, a%b)
        # dx = a - b
        # q = (dx+b-1) // b
        # return dfs(b, a-q*b)

    return "YES" if dfs(A,B) else "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
