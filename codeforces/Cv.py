import sys
from random import randint
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve(a,s):
    res = []
    a, s = a[::-1], s[::-1]
    dl = max(0, len(s) - len(a))
    a += '0'*dl
    N, M = len(a), len(s)

    j = 0
    for i in range(N):
        if j == M and N-i-1 < dl: break
        if j >= M and N-i-1 >= dl: return -1

        c, d = int(a[i]), int(s[j])
        if c <= d:
            res += [str(d-c)]
            j += 1
        else:
            if j+1 >= M: return -1
            q = int(s[j:j+2][::-1])
            if q-c > 9: return -1
            if q-c < 0: return -1
            res += [str(q-c)]
            j += 2
    return ''.join(res[::-1]).lstrip('0')

def test():
    a = s = ""
    i = randint(1,15)
    j = randint(4,18)
    for x in range(i): a += str(randint(0,9))
    for x in range(j): s += str(randint(0,9))
    print("TEST: ")
    print(a, s)
    q = int(solve(a, s))
    print(q)
    print()
    return q != -1

if __name__ == '__main__':
    # t = 0
    # while t < 100:
    #     t += int(test())
    T, = intput()
    for _ in range(T):
        a,s = input().split()
        print( solve(a,s) )
