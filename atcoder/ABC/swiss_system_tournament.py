intput = lambda : map(int, input().split())
N, M = intput()
A = [input() for _ in range(2*N)]
rank = list(range(2*N))
wins = [0] * (2*N)

def rps(a, b, m):
    if m == ('G', 'C'): wins[a] += 1
    if m == ('C', 'G'): wins[b] += 1
    if m == ('C', 'P'): wins[a] += 1
    if m == ('P', 'C'): wins[b] += 1
    if m == ('P', 'G'): wins[a] += 1
    if m == ('G', 'P'): wins[b] += 1

for r in range(M):
    for i in range(N):
        a, b = rank[2*i], rank[2*i+1]
        c, d = A[a][r], A[b][r]
        rps(a, b, (c,d))
    rank.sort(key = lambda i : (-wins[i], i))

for r in rank:
    print(r+1)
