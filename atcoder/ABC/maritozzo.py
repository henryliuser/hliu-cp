S = [input() for _ in range(3)]
T = input()
ans = []
for t in T:
    ans.append(S[int(t)-1])
print( "".join(ans) )
