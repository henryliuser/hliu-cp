import sys
from heapq import heappush, heappop, heapify
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, K = intput()
    P = list(intput())
    heapify(pq := P[:K-1])
    for i in range(K-1, N):
        heappush(pq, P[i])
        while len(pq) > K:
            heappop(pq)
        print(pq[0])
