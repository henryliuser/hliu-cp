import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(i):
    print('?', i)
    sys.stdout.flush()
    x, = intput()
    return x

def submit(A):
    print('!', *A)
    sys.stdout.flush()

def solve():
    N, = intput()
    done = [False] * N
    for i in range(N):
        if done[i]: continue
        s = set()
        while 1:
            x = query(i)
            if x in s: break
            s.add(x)




def permute(A, P):
    return [A[x-1] for x in P]

def test():
    from itertools import permutations
    from random import randint as rng
    N = 7
    Q = list(range(1,N+1))
    allP = list(permutations(Q))
    f = len(allP)
    # P = allP[ rng(0,f-1) ]
    P = [5,6,4,7,3,1,2]
    for _ in range(N+2):
        print(Q)
        Q = permute(Q, P)

if __name__ == '__main__':
    test()
    # t, = intput()
    # for _ in range(t):
    #     solve()
