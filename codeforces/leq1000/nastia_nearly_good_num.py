def solve():
    a, b = map(int, input().split())
    if b == 1: return "NO"
    if (a*b-a) == a: b *= 2
    return (a, a*b-a, a*b)

T = int(input())
for _ in range(T):
    s = solve()
    if s == "NO": print(s)
    else: print("YES\n" + " ".join(map(str, s)))
