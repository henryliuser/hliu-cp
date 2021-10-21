import sys
intput = map(int, input().split())

if __name__ == '__main__':
    sys.stdin  = open('poetry.in',  'r')
    sys.stdout = open('poetry.out', 'w')
    N, M, K = intput()
    
