from collections import defaultdict

c = defaultdict(int)
nb = ['A', 'C', 'G', 'T']
for ch in input(): c[ch] += 1
print(*[c[x] for x in nb])
