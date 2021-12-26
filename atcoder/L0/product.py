import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, X = intput()
    grid = [[0,[]] for _ in range(N)]
    for i in range(N):
        L = list(intput())
        grid[i][0] = L[0]
        grid[i][1] = L[1:]

    ans = 0
    def dfs(i, j, k):
        global ans
        k *= grid[i][1][j]
        if i == N-1:
            ans += int(k==X)
            return
        for q in range(grid[i+1][0]):
            dfs(i+1, q, k)

    for j in range(grid[0][0]):
        dfs(0, j, 1)

    print(ans)
