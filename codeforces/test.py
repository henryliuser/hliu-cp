import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def sm(s, n):
    return sum(s+i for i in range(n))

def solve(x):
    for i in range(-100, 100):
        r = sm(i, 2)
        for j in range(-100, 100):
            c = sm(j, 6)
            if r + c == x:
                return i, j


if __name__ == '__main__':
    print(solve(28))
