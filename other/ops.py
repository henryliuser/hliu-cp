ops = 0
for i in range(10000):
    for j in range(i):
        ops += 1
print(ops)

ops = 0
for i in range(10000):
    for j in range(10000):
        ops += 1
print(ops)
