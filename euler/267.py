from random import randint
def dfs(i, f, curr, target):
    global good, total
    if i == N:
        good += int(curr >= target)
        total += 1
        return
    bet = f * curr
    dfs(i+1, f, curr+2*bet, target)
    dfs(i+1, f, curr-bet, target)

f = 0.5
N = 21
while f <= 1:
    good = total = 0
    dfs(1, f, 1, 25000)
    print(f"{f:.2g}", good/total)
    f += 0.01
