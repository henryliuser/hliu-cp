import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    ans = {1}
    for i in range(2, N+1):
        if i*i > N: break
        ans.add(i*i)
    for i in range(2, N+1):
        if i*i*i > N: break
        ans.add(i*i*i)
    return len(ans)


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
