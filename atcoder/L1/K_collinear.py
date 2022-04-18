# https://atcoder.jp/contests/abc248/tasks/abc248_e
# loop on all pairs and mark exclusion
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
if __name__ == '__main__':
    N, K = intput()
    if K == 1:
        print("Infinity")
        exit()

    A = []
    for i in range(N):
        x, y = intput()
        A += [ (x,y) ]

    def area(x1,y1,x2,y2,x3,y3):
        return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)

    ans = 0
    vis = [ [0]*N for _ in range(N) ]
    for i in range(N):
        for j in range(i+1, N):
            cnt = 2
            t = []
            if vis[i][j]: continue
            vis[i][j] = vis[j][i] = 1
            for k in range(N):
                if k == i or k == j: continue
                if area(*A[i], *A[j], *A[k]) == 0:  # collinear
                    if vis[i][k] or vis[j][k]: break
                    t += [k]
                    cnt += 1
            else:
                if cnt >= K:
                    ans += 1
                    for k in t:
                        vis[i][k] = vis[k][i] = 1
                        vis[j][k] = vis[k][j] = 1
    print(ans)
