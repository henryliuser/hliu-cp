n = int(input())
d = {'A':0, 'D':0}
for c in input(): d[c] += 1
a = d['A']
b = d['D']
if (a < b): print("Danik")
elif a > b: print("Anton")
else: print("Friendship")
