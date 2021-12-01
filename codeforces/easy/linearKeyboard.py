# https://codeforces.com/problemset/problem/1607/A
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans, kb = 0, {}
    for i,ch in enumerate(input()):
        kb[ch] = i
    s = input()
    pos = kb[ s[0] ]
    for i in range(1, len(s)):
        x = kb[s[i]]
        ans += abs(pos - x)
        pos = x
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
