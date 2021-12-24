# probably faster to solve this with prefix sum, but this works for
# L,R <= 1e9. Next time, if N! is small just hard-code all permutations.
# or just think of prefix sum first and realize it works
# answer each query in log(R), count 0 bits using cycles and math
import sys
from math import log2
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(L, R):
    ans = float('inf')
    dx = R - L + 1
    B = int(log2(R)) + 1
    for b in range(B):
        cnt = 0
        zeros = int( 2**b )
        cyc = int( 2**(b+1) )
        n = dx // cyc
        cnt += n * zeros
        l = L % cyc
        r = R % cyc

        def corner():
            z = zeros
            if dx % cyc == 0: return 0
            if l <= z <= r: return z - l
            if l <= r <= z: return r - l + 1
            if r <= z <= l: return r + 1
            if r <= l <= z: return z - l + r + 1
            if z <= l <= r: return 0
            if z <= r <= l: return z
            return 0

        cnt += max(0, corner())
        ans = min(ans, cnt)
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        L, R = intput()
        print( solve(L, R) )
