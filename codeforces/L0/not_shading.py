import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    flag = [0,0,0]
    n,m,r,c = intput()
    r,c = r-1,c-1
    for i in range(n):
        s = input()
        for j in range(m):
            if s[j] == 'W': continue
            flag[0] = 1
            if (i,j) == (r,c): flag[2] = 1
            if i == r or j == c:
                flag[1] = 1
    if flag[2] == 1: return 0
    if flag[0] == 0: return -1
    return 1 if flag[1] else 2

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
