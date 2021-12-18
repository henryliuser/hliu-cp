def solve():
    N = input()
    L = len(N)
    first = N[0]
    minus = False
    near = int(first*L)
    if (int(N) < near): minus = True
    return (L - 1) * 9 + int(first) - int(minus)

T = int(input())
for _ in range(T):
    print(solve())
