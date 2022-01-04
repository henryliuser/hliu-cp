import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A, B = input(), input()
    if A == B: return 0

    ones  = [0, 0]  # 0:A, 1:B
    swaps = [0, 0]  # 0:A, 1:A^-1
    for i in range(N):
        ones[0]  += (A[i] == '1')
        ones[1]  += (B[i] == '1')
        swaps[0] += (A[i] != B[i])
        swaps[1] += (A[i] == B[i])

    if ones[0] == 0: return -1
    if ones[1] != ones[0] and ones[1] != N-ones[0]+1:
        return -1

    ans = float('inf')
    if ones[0] == ones[1]:  # even condition
        ans = swaps[0]
    if ones[1] == N - ones[0] + 1:  # odd condition
        for i in range(N):
            if A[i] == '1':
                if A[i] == B[i]: ans = min(ans, swaps[1])
                if A[i] != B[i]: ans = min(ans, swaps[1]+1)
    return ans

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        print( solve() )
