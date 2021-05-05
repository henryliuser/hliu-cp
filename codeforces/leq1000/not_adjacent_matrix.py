dirs = [(1,0), (-1,0), (0,1), (0,-1)]

def solve():
    N = int(input())
    arr = [[0]*N for _ in range(N)]
    arr[0][0] = 1
    midCols = N-2
    L, R = 1, N**2
    usingL = True
    for r in range(N):
        for c in range(N):
            arr[r][c] = L if usingL else R
            if usingL: L += 1
            else: R -= 1
            usingL = not usingL
    arr[0][0], arr[-1][-1] = arr[-1][-1], arr[0][0]
    for r in range(N):
        for c in range(N):
            for d in dirs:
                x, y = r+d[0], c+d[1]
                if 0 <= x < N and 0 <= y < N:
                    if abs(arr[x][y] - arr[r][c]) == 1:
                        return -1
    return arr

for _ in range(int(input())):
    s = solve()
    if s == -1: print(s)
    else:
        for row in s:
            print(" ".join(map(str,row)))
