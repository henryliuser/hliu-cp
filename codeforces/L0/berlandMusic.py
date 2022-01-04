import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    P  = list( intput() )
    A  = input()
    like, dont = [], []
    for i, ch in enumerate(A):
        if ch == '1': like += [i]
        if ch == '0': dont += [i]

    like.sort(key = lambda i : P[i])
    dont.sort(key = lambda i : P[i])

    ans = [-1] * N
    all = dont + like
    for i,j in enumerate(all):
        ans[j] = i+1

    return ans

if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        print( *solve() )
