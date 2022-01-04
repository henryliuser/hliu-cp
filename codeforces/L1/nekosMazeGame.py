import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    cur = 0
    N, Q = intput()
    blocks = [0] * N
    grid = [[False] * N for _ in range(2)]

    def find(r, c):  # number of X's around (r,c)
        res = 0
        for i in (c-1, c, c+1):
            if 0 <= i < N and grid[r][i]:
                res += 1
        return res

    def adjust(r, c):
        global cur
        clear = 1 if grid[r][c] else -1
        grid[r][c] = not grid[r][c]
        cur += clear * find(1^r, c)

    for _ in range(Q):
        r, c = intput()
        adjust(r-1, c-1)
        print("No" if cur else "Yes")
