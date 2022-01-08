import sys
from bisect import bisect_left
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def gen():
    ans = set()
    N = int(1e18+1)
    for i in range(10):
        for dx in range(10):
            x = [i]
            while len(x) < 19:
                y = x[-1] + dx
                if y >= 10: break
                x += [y]
                ans.add( int(''.join(map(str, x[::-1]))) )
                ans.add( int(''.join(map(str, x))) )

    return sorted(ans)

if __name__ == '__main__':
    arith = gen()
    X, = intput()
    i = bisect_left(arith, X)
    print(arith[i])
