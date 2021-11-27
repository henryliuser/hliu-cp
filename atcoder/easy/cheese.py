import sys
input = lambda : sys.stdin.readline().split()
intput = lambda : map(int, input())

def solve():
    A = []
    N, W = intput()
    for _ in range(N):
        a, b = intput()
        A.append( (-a,b) )
    A.sort()

    ans = 0
    for a,b in A:
        m = min(W, b)
        W -= m
        ans -= a*m
        if W <= 0: break
    return ans

if __name__ == '__main__':
    print( solve() )
