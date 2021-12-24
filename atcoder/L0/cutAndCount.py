import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    ans = 0
    N, = intput()
    S = input()
    dp = [set() for _ in range(N)]
    for i in range(N):
        if i: dp[i] = set(dp[i-1])
        dp[i].add(S[i])

    curr = set()
    for i in range(N-1, 0, -1):
        curr.add(S[i])
        ans = max(ans, len(curr & dp[i-1]))

    print(ans)
