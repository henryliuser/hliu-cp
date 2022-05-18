import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    ans = []
    N, A, B = intput()
    for i in range(N):
        for r in range(A):
            line = []
            for j in range(N):
                ch = '#' if (i+j)%2 else '.'
                line += [ch * B]
            print(''.join(line))
