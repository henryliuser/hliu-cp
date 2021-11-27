def solve():
    N = int(input())
    board = list(input())
    maxStreak = 0
    L, R = 0, 0
    curr = 0
    last = ''
    sheep = []
    for x in range(N): # find longest streak
        if board[x] == '*':
            sheep.append(x)
    ls = len(sheep) // 2
    if ls == 0: return 0
    L, R, = sheep[ls], sheep[ls]
    ans = 0
    for x in range(L-1, -1, -1):
        if board[x] == '*':
            board[x] = '.'
            ans += L - x - 1
            L -= 1
    for x in range(R+1, N):
        if board[x] == "*":
            board[x] = '.'
            ans += x - R - 1
            R += 1
    print(ans)

for _ in range(int(input())):
    if (solve() == 0): print(0)
