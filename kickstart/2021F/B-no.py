from heapq import heappush, heappop
intput = lambda : map(int, input().split())

def solve(t):
    ans = 0
    D, N, K = intput()
    days = [[] for _ in range(D+1)]
    for _ in range(N):
        h, s, e = intput()
        days[s].append(h)
        days[e+1].append(-h)

    curr = defaultdict(int)
    sum, pq = 0, []
    for d in days:
        if not d: continue
        for h in d:
            if h > 0:
                if len(pq) < K:
                    heappush(pq, h)
                    curr.add(h)
                    sum += h
                elif h > pq[0]:  # len(pq) >= K
                    rm = heappop(pq)
                    sum += h - rm
                    heappush(pq, h)
                    curr.remove(rm)
            if h < 0:
                if -h in curr:
                sum -= heappop(pq)
        ans = max(ans, sum)
    print(f"Case #{t}: {sum}")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        solve(i+1)
