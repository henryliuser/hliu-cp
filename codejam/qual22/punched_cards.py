# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    R, C = intput()
    s = '-'.join('+'*(C+1))
    t = '.'.join('|'*(C+1))
    ans = []
    for i in range(R):
        ans += [[*s]]
        ans += [[*t]]
    ans += [[*s]]
    ans[0][:2] = ['.', '.']
    ans[1][:2] = ['.', '.']
    return '\n'.join([''.join(x) for x in ans])

if __name__ == '__main__':
    T, = intput()
    for t in range(T):
        print(f"Case #{t+1}:")
        print( solve() )
