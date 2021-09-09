from collections import defaultdict

N = int(input())
count = defaultdict(int)
def convert(x):
    s = [str(d%2) for d in map(int, x)]
    return int("".join(s))

for _ in range(N):
    a,b = input().split()
    c = convert(b)
    if a == '?':
        print(count[c])
    if a == '+':
        count[c] += 1
    if a == '-':
        count[c] -= 1
