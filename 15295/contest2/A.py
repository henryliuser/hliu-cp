from heapq import heappush, heappop
N = int(input())
pq = []
ans = []
for _ in range(N):
    i = input()
    if i == 'removeMin':
        if not pq:
            ans.append('insert 0')
            heappush(pq, 0)
        ans.append('removeMin')
        heappop(pq)
        continue
    a, b = i.split()
    b = int(b)
    if a == 'insert':
        ans.append(f'insert {b}')
        heappush(pq, b)
    if a == 'getMin':
        if not pq or b < pq[0]:
            ans.append(f'insert {b}')
            ans.append(f'getMin {b}')
            heappush(pq, b)
        elif b > pq[0]:
            while pq and pq[0] < b:
                ans.append('removeMin')
                heappop(pq)
            if not pq or pq[0] != b:
                ans.append(f'insert {b}')
                heappush(pq, b)
            ans.append(f'getMin {b}')
        elif b == pq[0]:
            ans.append(f'getMin {b}')


print(len(ans))
print("\n".join(ans) + "\n")
