# https://codeforces.com/contest/1624/problem/B
# a lesson in haste. verify all conditions
import sys
from random import randint as rng
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(a, b, c):
    d1, d2 = b-a, c-b
    if d1 == d2: return "YES"
    q = d1 + b
    if q % c == 0 and (q // c) > 0: return "YES"
    q = b - d2
    if q % a == 0 and (q // a) > 0: return "YES"
    q = c + a
    if q % (2*b) == 0 and (q // (2*b)) > 0: return "YES"
    return "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        s = solve(*intput())
        print(s)
