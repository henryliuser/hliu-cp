alph0 = {}
alph1 = {}
i = 0
for x in input():
    alph0[x] = i
    alph1[i] = x
    i += 1

ans = []
N = int(input())
for _ in range(N):
    s = input()
    key = tuple(alph0[ch] for ch in s)
    ans.append(key)

ans.sort()
for a in ans:
    print("".join(alph1[k] for k in a))
    
