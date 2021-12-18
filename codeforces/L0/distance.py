import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def dist(a,b,c,d):
    return abs(a-c) + abs(b-d)

def solve():
    x, y = intput()
    z = x+y
    if z % 2: return [-1, -1]
    if not (x%2 or y%2): return [x//2, y//2]
    for i in range(51):
        for j in range(51):
            if 2*dist(0,0,i,j) == dist(0,0,x,y):
                if 2*dist(x,y,i,j) == dist(0,0,x,y):
                    return [i,j]

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
