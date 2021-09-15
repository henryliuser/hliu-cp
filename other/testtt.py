s = set()

for j0 in range(375):
    for i0 in range(675):
        j1 = j0 + 375
        i1 = i0 + 625
        i00, i01 = (j0, i0), (j0, i1)
        i10, i11 = (j1, i0), (j1, i1)
        # print(i00, i01, i10, i11)
        s.add((j0, i0))
        s.add((j0, i1))
        s.add((j1, i0))
        s.add((j1, i1))

# print(len(s))

s2 = {1, 3, 9, 100, 5, 2, 4, 6}
for k in s2:
    s2.remove(k)
    print(k)
    s2.add(k)
