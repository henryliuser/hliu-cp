import sys

# kinda lame, just LCS with 1 line change
if __name__ == '__main__':
    sys.stdin  = open('nocross.in',  'r')
    sys.stdout = open('nocross.out', 'w')
    intput = lambda: int(input())
    N = intput()
    dp = [[0] * (N+1) for _ in range(2)]
    A, B = [], []
    for _ in range(N):
        A.append(intput())
    for _ in range(N):
        B.append(intput())

    for i in range(1, N+1):
        t = i%2
        for j in range(1, N+1):
            a,b = A[i-1], B[j-1]
            if abs(a-b) <= 4:
                dp[t][j] = 1 + dp[not t][j-1]
            else:
                dp[t][j] = max(dp[not t][j], dp[t][j-1])

    print( dp[N%2][N] )
