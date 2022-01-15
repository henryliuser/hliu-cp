from math import gcd
a = [48, 49, 74, 75, 156, 157, 140, 141, 6, 7, 46, 47, 58, 59, 22, 23, 20, 21, 60, 61, 138, 139, 12, 13, 122, 123, 38, 39, 112]
for i in range(1, len(a)):
    x,y = a[i-1], a[i]
    if gcd(x, y) != 1:
        print(i, x, y)
