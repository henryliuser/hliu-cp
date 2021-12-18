# https://codeforces.com/problemset/problem/1620/C
# fun question. math + implementation
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def toStr(new, res):
    a = []
    n = len(new)
    c = 0
    for i in range(n):
        if new[i] == 'a':
            a.append('a')
        else:
            a.append('b' * res[c])
            c += 1
    return "".join(a)

def solve(k,x,s):
    s += "$"
    stk = 0
    new = []
    for i, ch in enumerate(s):
        if ch == '*': stk += 1
        else:
            if i != 0 and s[i-1] != 'a':
                new.append(stk)
                stk = 0
        if ch == 'a':
            new.append('a')
    q = [y for y in new if y != 'a']
    if not q: return s[:-1]
    n = len(q)
    for i in range(n):
        q[i] = q[i] * k + 1
    for i in range(n-2, -1, -1):
        q[i] *= q[i+1]
    x -= 1

    for i in range(n-1, -1, -1):
        if q[i] > x: break

    res = [0] * n
    if i == n-1:
        res[i] = x
        return toStr(new, res)

    while i < n-1:
        b = x // q[i+1]
        x %= q[i+1]
        res[i] = b
        i += 1
    res[-1] = x
    return toStr(new, res)


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        n, k, x = intput()
        s = input()
        print( solve(k,x,s) )

from random import randint
def random():
    b = []
    for i in range(randint(0,50)):
        a = randint(0,1)
        x = randint(0,20)
        if a == 0:
            b.append(x * '*')
        else:
            b.append(x * 'a')
    return ''.join(b)


def test(x, k, s):
    A = set()
    def dfs(i, curr):
        if i >= len(s):
            A.add(str(curr))
            return
        if s[i] == '*':
            for j in range(k+1):
                q = curr + 'b'*j
                dfs(i+1, q)
        else: dfs(i+1, curr + 'a')
    dfs(0, "")
    return sorted(A)[x-1]
