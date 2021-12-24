import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

dirs = ( (0,1), (1,0), (-1,0), (0,-1), (1,1), (1,-1), (-1,1), (-1,-1) )
if __name__ == '__main__':
    H, W = intput()
    grid = [list(input()) for _ in range(H)]

    for i in range(H):
        for j in range(W):
            if grid[i][j] == '#': continue
            grid[i][j] = 0
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < H and 0 <= y < W:
                    if grid[x][y] == '#':
                        grid[i][j] += 1

    for g in grid:
        print(*g, sep='')
