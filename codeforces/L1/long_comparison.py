import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    x, xp = input().split()
    y, yp = input().split()
    xp, yp = int(xp), int(yp)
    xd = len(x) + xp
    yd = len(y) + yp
    if xd > yd: return ">"
    elif xd < yd: return "<"

    flip = False
    if len(x) < len(y):
        x,y = y,x
        flip = True
    dl = len(x) - len(y)
    y = y + "0"*dl
    for a,b in zip(x,y):
        if a > b: return ">" if not flip else "<"
        if a < b: return "<" if not flip else ">"
    return "="


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
