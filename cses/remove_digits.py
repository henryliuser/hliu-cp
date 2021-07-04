N = input()
n = int(N)

c = 0
while n != 0:
    n -= max(map(int, N))
    N = str(n)
    c += 1

print(c)
