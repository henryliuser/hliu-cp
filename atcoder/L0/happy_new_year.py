import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    K, = intput()
    print( bin(K)[2:].replace('1', '2') )
