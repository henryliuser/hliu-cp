pair = count = 0
asd = (['r'] * 5) + (['b'] * 6)
for x in range(11):
    for y in range(x+1, 11):
        if asd[x] == asd[y]: pair += 1
        count += 1
print(pair, count)
print(pair/count)
