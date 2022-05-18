import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    H, W = intput()
    R, C = intput()
    dirs = [(0,1), (1,0), (0,-1), (-1,0)]
    print( sum( (0<R+x<=H and 0<C+y<=W) for x,y in dirs) )
