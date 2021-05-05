def solve():
    N = int(input())
    board = list(input())
    maxStreak = 0
    L, R = 0, 0
    curr = 0
    last = ''
    for x in range(N): # find longest streak
        b = board[x]
        if b == "*":
            curr += 1
        else:
            if curr > maxStreak:
                maxStreak = curr
                L, R = x-curr, x-1
            curr = 0
        last = b
    if curr > maxStreak:
        maxStreak = curr
        L, R = x-curr+1, x

    ans = 0
    for x in range(L-1, -1, -1):
        if board[x] == '*':
            board[x] = '.'
            ans += L - x - 1
            L -= 1
            if N == 10: print(x, ans, L)
    for x in range(R+1, N):
        if board[x] == "*":
            board[x] = '.'
            ans += x - R - 1
            R += 1
    print(ans)




for _ in range(int(input())):
    solve()
