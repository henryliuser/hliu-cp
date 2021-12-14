import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def dist(x1, y1, x2, y2):
    dx = abs(x2-x1)
    dy = abs(y2-y1)
    return dx * dx + dy * dy

if __name__ == '__main__':
    ans = 
    rx1, ry1, rx2, ry2 = intput()
    N, = intput()
    pts = [tuple(intput()) for _ in range(N)]
    pts.sort(key=lambda x,y: dist(x,y,rx1,ry1))

    for i in range(N+1):
