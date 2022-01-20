import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(N, A):
    ans = 0
    xs = [[], []]
    for x in A:
        if x < 0: continue
        xs[x%2] += [x]

    xs[0].sort(), xs[1].sort()
    j = len(xs[1]) % 2

    a = sum(xs[0])
    b = sum(xs[1][j:])
    return a + b

if __name__ == '__main__':
    N, = intput()
    A  = list(intput())
    print( solve(N, A) )
