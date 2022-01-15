import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(r):
    print('?', 1, r+1)
    sys.stdout.flush()
    r, = intput()
    return r

def submit(x):
    print('!', x)
    sys.stdout.flush()

if __name__ == '__main__':
    n, t = intput()
    k, = intput()
    lo, hi = 0, n-1
    while lo < hi:
        mid = (lo+hi) // 2
        if mid + 1 - query(mid) < k:
            lo = mid + 1
        else:
            hi = mid
    submit(lo+1)
