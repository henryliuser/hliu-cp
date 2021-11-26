import sys
# input = sys.stdin.readline
# intput = lambda : map(int, input().split())

def solve():
    s = input()
    ok = False
    for ch in s:
        x = int(ch)
        if x % 2 == 0:
            ok = True
    if not ok: return -1

    if int(s[-1]) % 2 == 0:
        return 0
    if int(s[0]) % 2 == 0:
        return 1
    
    return 2


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        print( solve() )
