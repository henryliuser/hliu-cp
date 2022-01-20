import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(N, A):
    cnt = [0,0]
    for x in A:
        if x != 0: cnt[x>0] += 1
    if cnt[0] >= (N+1)//2: return -1
    if cnt[1] >= (N+1)//2: return 1
    return 0

if __name__ == '__main__':
    N, = intput()
    A  = list(intput())
    print( solve(N,A) )
