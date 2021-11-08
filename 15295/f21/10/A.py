intput = lambda : map(int, input().split())

def solve():
    N, Q = intput()
    S = input()

    def query(L, R):
        if L == R: return "NO"
        c, i = L, 0
        start, broke = False, False
        while i < len(S) and c <= R:
            if S[i] == S[c] and c == R and broke: return "YES"
            if S[i] == S[c] and c == R-1 and not broke:
                c, i, broke = c+1, i+1, True
                start = True
            elif S[i] == S[c]:
                c += 1
                start = True
            elif start:
                broke = True
            i += 1
        return "YES" if c > R and broke else "NO"

    for _ in range(Q):
        l, r = intput()
        print(query(l-1, r-1))


T, = intput()
for _ in range(T):
    solve()
