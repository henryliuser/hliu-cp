import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def onLine(m, b, x, y):
    return m * x + b == y

def solve(N, Y):
    for i in range(1, N):
        L2 = []
        m1 = (Y[i] - Y[0]) / i
        b1 = Y[0]
        for x in range(1, N):
            if i == x: continue
            if not onLine(m1, b1, x, Y[x]):
                L2.append(x)

        ok = True
        if len(L2) == 0: continue
        if len(L2) == 1: return "Yes"
        m2 = (Y[L2[1]] - Y[L2[0]]) / (L2[1] - L2[0])
        b2 = Y[L2[0]] - m2 * L2[0]
        if m1 != m2: continue
        if b1 == b2: continue
        if len(L2) == 2: return "Yes"

        for j in range(2, len(L2)):
            x = L2[j]
            if not onLine(m2, b2, x, Y[x]):
                ok = False
                break
        if ok: return "Yes"

    # now attempt x=0 is the solo line
    m = (Y[2] - Y[1])
    b = Y[1] - m
    for x in range(3, N):
        if not onLine(m, b, x, Y[x]):
            return "No"

    return "No" if onLine(m, b, 0, Y[0]) else "Yes"


if __name__ == '__main__':
    N, = intput()
    Y = list(intput())
    print( solve(N,Y) )
