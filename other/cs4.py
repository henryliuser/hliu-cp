# Given a list[int] A, transform into a single maximum number
# by swapping any two elements i,j with 2*min(i,j).

# O(N log N)
from heapq import heappush, heappop, heapify
def maximum_num(A: list) -> int:
    N = len(A)
    heapify(pq := A[:])    # N log N
    for _ in range(N-1):   # N
        i = heappop(pq)    #  log N
        j = heappop(pq)    #  log N
        new = 2 * min(i,j)
        heappush(pq, new)  #  log N

    return pq[0]

if __name__ == '__main__':
    print(maximum_num([7,8,53,1,2,3]))  # 32
