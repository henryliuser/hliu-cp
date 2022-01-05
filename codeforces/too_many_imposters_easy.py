import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(a, b, c):
    print('?', a, b, c)
    sys.stdout.flush()
    x, = intput()
    if x == -1: exit()
    return x

def submit(A):
    print('!', *A)
    sys.stdout.flush()



if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        solve()
