# stop bags
import sys
from bisect import *
from collections import *
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    l,r,a = intput()
    if l == r:
        return r//a + r%a
    q = r//a

    f1 = q + r % a
    if r%a == 0:
        f2 = q-1 + (a-1)
        return max(f1,f2)

    if l < q*a:
        f2 = q-1 + (a-1)
        return max(f1, f2)

    return f1
    

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
