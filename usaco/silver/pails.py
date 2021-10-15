import sys
intput = lambda : map(int, input().split())

dp = set()
ans = float('inf')
def dfs(i, b1, b2):
    global ans
    ans = min(ans, abs(b1+b2 - M))
    if i == K: return
    if (b1, b2) in dp: return
    dp.add( (b1, b2) )
    dfs(i+1, X, b2)
    dfs(i+1, b1, Y)
    dfs(i+1, 0, b2)
    dfs(i+1, b1, 0)
    d1 = X - b1
    d2 = Y - b2
    m21 = min(d1, b2)
    m12 = min(d2, b1)
    dfs(i+1, b1+m21, b2-m21)
    dfs(i+1, b1-m12, b2+m12)

if __name__ == '__main__':
    sys.stdin  = open('pails.in',  'r')
    sys.stdout = open('pails.out', 'w')
    X, Y, K, M = intput()
    dfs(0, 0, 0)
    print(ans)
