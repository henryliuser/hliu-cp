import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    N, = intput()
    A = sorted(intput())
    for j in range(N):
        p = 0
        B = A[:]
        for i in range(N):
            if i == j: continue
            while B[i] % 2 == 0:
                B[i] //= 2
                p += 1
        B[j] *= pow(2,p)
        ans = max(ans, sum(B))

    return ans
 
if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
