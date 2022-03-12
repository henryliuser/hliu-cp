# https://codeforces.com/contest/1647/problem/D
# unsure why this works.
# First you factorize x, then remove the non-multiples of d.
# These are all the good numbers that are candidates for multiplying to x.
# Let's let N be the length of these remaining good numbers. N ~ O(sqrt(x))
# Now, we want to determine which ones of these are beautiful.
# After running some examples in my head, it seemed like for
# each good number g, we can just check to see if g/d is also good.
# If g/d is good, then g is not beautiful. Otherwise, g is beautiful.
# We can do this in O(N) or O(N log N) with hashing/sorting.
# Now we have our remaining beautiful numbers.
# We just need to find 2 different ways to multiply to x.
# I tried locally with some huge numbers, and the length
# of the remaining beautiful numbers is very small (around 15-20 for x=1e9).
# So i just did backtracking dfs over the numbers and divided until i got to 1.
import sys
enum   = enumerate
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def facts(x):
    s, z = set(), 1
    while z*z <= x:
        if x % z == 0:
            s.add(x//z)
            s.add(z)
        z += 1
    return s

def solve():
    x, d = intput()
    fac = facts(x)
    good = [f for f in fac if f%d == 0]
    good.sort()

    beau, seen = set(), set()
    for k,y in enum(good):
        z = y // d
        if z not in seen:
            beau |= {y}
        seen.add(y)

    ans = set()
    if x in beau:
        ans |= { (x,) }
        beau.remove(x)

    def dfs(x, p=[]):
        if x <= 1: return
        for b in beau:
            if x % b: continue
            c = x//b
            p += [b]
            if c in beau:
                p += [c]
                t = tuple(sorted(p))
                ans.add(t)
                if len(ans) >= 2:
                    raise OSError()
                p.pop()
            dfs(c)
            p.pop()

    try:
        dfs(x)
        return "NO"
    except OSError:
        return "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
