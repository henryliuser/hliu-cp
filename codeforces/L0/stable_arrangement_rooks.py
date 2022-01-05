import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, K = intput()
    ok = (N-1) // 2 + 1 >= K
    if not ok: return -1
    grid = [['.']*N for _ in range(N)]
    for i in range(K):
        j = 2*i
        grid[j][j] = 'R'
    return grid

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        s = solve()
        if s == -1: print(s)
        else:
            for l in s:
                print(''.join(l))
