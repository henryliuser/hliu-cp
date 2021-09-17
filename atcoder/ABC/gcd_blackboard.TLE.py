from collections import Counter
intput = lambda : map(int, input().split())

ans = 1
N, = intput()
A  = list(intput())
pre = [defaultdict(int)]

def factors(x):
    pass

for i in range(N):
    pre.append(pre[-1].copy())
    for f in factors(A[i]):
        pre[-1][f] += 1

def intersect(a, b):
    d = defaultdict(int)
    keys = set(a) & set(b)
    for k in keys:
        d[k] = a[k] + b[k]
    return d

for i in range(N):  # exclude i
    leftA, leftB = pre[0], pre[max(i-1, 0)]
    rightA, rightB = pre[min(i+2, N)], pre[-1]
    left  = intersect(leftA, leftB)
    right = intersect(rightA, rightB)
    final = intersect(left, right)
    for f in final:
        if final[f] == N-1:
            ans = max(ans, f)

print(ans)

    
