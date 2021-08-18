# Prefix Sums
A = [1,4,2,-6,4,2,0,9,100,12] # ... 10000
queries = [(0,1), (2,5), (3,5), (7,9)]
N = len(A)
Q = len(queries)


# for each query q in Q, print the sum of
# the elements in A, from q[0] to q[1] inclusive

# O(NQ)
for l,r in Q:
    s = 0
    for x in range(l, r+1):
        s += A[x]
    print(s)

# O(N+Q)
pre = [0]
for n in A:
    pre.append(n + pre[-1])
for l,r in Q:
    print(pre[r+1] - pre[l])
