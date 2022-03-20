import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    pre = [0]
    for x in intput():
        pre += [ pre[-1] + x - (x==0) ]
    print(pre)
    print(len(set(pre)))
