def solve():
    N = int(input())
    tasks = input()
    done = set()
    for x in range(1, N):
        a, b = tasks[x-1], tasks[x]
        if b in done: return "NO"
        if b == a: pass
        else: done.add(a)
    return "YES"

T = int(input())
for _ in range(T):
    print(solve())
