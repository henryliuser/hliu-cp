import sys

roads = set()  # (r, c, r', c')
dirs = ((0,1), (1,0), (-1,0), (0,-1))

def dfs(r, c):
    global i  # how many cows we've seen before
    if (r, c) in cows: i -= 1
    seen[r][c] = True
    for d in dirs:
        x,y = r+d[0], c+d[1]
        if x < 1 or x > N or y < 1 or y > N:
            continue
        if seen[x][y] or (r,c,x,y) in roads or (x,y,r,c) in roads:
            continue
        dfs(x,y)


if __name__ == '__main__':
    sys.stdin  = open('countcross.in',  'r')
    sys.stdout = open('countcross.out', 'w')
    intput = lambda: map(int, input().split())
    ans = 0
    N, K, R = intput()
    cows = set()
    for _ in range(R):
        a, b, c, d = intput()
        roads.add( (a,b,c,d) )
    cows.add( tuple(intput()) )
    for i in range(1, K):
        a, b = intput()
        seen = [[False]*(N+1) for _ in range(N+1)]
        dfs(a, b)
        ans += i
        cows.add( (a,b) )

    print(ans)
