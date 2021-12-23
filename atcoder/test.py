from random import randint
n = 5
print(n)
for _ in range(n):
    L = randint(2, 100)
    V = L + randint(-10, 10)
    A = [randint(0,9) for _ in range(L)]
    B = [randint(0,9) for _ in range(V)]
    print(''.join(map(str,A)))
    print(''.join(map(str,B)))
