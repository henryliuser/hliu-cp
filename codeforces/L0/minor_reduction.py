import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    s = [int(ch) for ch in input()]
    conv = lambda : ''.join( map(str, s) )

    for i in range(1, len(s)):
        x, y = s[~i], s[-i]
        if x+y > 9:
            s[~i], s[-i] = x+y, ''
            return conv()
    s[0] = s[0] + s[1]
    s[1] = ''
    return conv()

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
