import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, A, B = intput()
    P, Q, R, S = intput()
    r1 = max(1-A, 1-B)
    r2 = min(N-A, N-B)
    r3 = max(1-A, B-N)
    r4 = min(N-A, B-1)

    def painted(i, j):
        dx, dy = i-A, j-B
        if dx == dy:
            if r1 <= dx <= r2:
                return True
        dy = B-j
        if dx == dy:
            if r3 <= dx <= r4:
                return True
        return False

    for i in range(P, Q+1):
        for j in range(R, S+1):
            ch = '#' if painted(i,j) else '.'
            print(ch, end='')
        print()
