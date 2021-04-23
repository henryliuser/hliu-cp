t = int(input())
for q in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    for x in range(len(a)):
        if x == len(a)-1: break
        if k > a[x]:
            a[-1] += a[x]
            k -= a[x]
            a[x] = 0
        else:
            a[-1] += k
            a[x] -= k
            k = 0
        if k == 0: break
    print(" ".join(str(x) for x in a))
