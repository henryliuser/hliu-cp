import sys
from itertools import permutations
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    P = intput()
    for a,b,c in permutations(P):
        if a + b == c: return "Yes"
        if a % 2 == 0 and b == c: return "Yes"
    return "No"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
