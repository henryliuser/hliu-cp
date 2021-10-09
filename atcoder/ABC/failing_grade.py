N, P = map(int, input().split())
A = list(map(int, input().split()))
print(sum(1 for g in A if g < P))
