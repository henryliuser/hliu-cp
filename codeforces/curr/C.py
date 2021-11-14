import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def best(n, m):
    if m % 3 == 0: return m//3 * n
    if n % 3 == 0: return n//3 * m
    if (n, m) == (1, 2): return 1
    if (n, m) == (2, 1): return 1
    if (n, m) == (1, 4): return 2
    if (n, m) == (4, 1): return 2
    if (n, m) == (1, 5): return 2
    if (n, m) == (5, 1): return 2
    if (n, m) == (2, 2): return 2
    if n == 1:
        if m % 3 == 1: return 2 + (m-4) // 3
        if m % 3 == 2: return 1 + (m-2) // 3
    if m == 1:
        if n % 3 == 1: return 2 + (n-4) // 3
        if n % 3 == 2: return 1 + (n-2) // 3
    if n == 2:
        if m % 3 == 1: return 1 + 2*(m-1)//3
        if m % 3 == 2: return 2 + 2*(m-2)//3
    if m == 2:
        if n % 3 == 1: return 1 + 2*(n-1)//3
        if n % 3 == 2: return 2 + 2*(n-2)//3
    if m % 3 == 2: return best(n, m-2) + best(n, 2)
    if n % 3 == 2: return best(n-2, m) + best(2, m)
    if m % 3 == 1: return best(n, m-1) + best(n, 1)
    if n % 3 == 1: return best(n-1, m) + best(1, m)

def solve():
    n, m = intput()
    return best(n, m)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
