import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    S = input()
    K, = intput()
    i = ans = 0
    for j in range(len(S)):
        if S[j] == '.':
            K -= 1
        while K < 0:
            if S[i] == '.':
                K += 1
            i += 1
        ans = max(ans, j-i+1)
    return ans

if __name__ == '__main__':
    print( solve() )

# XX...X.X.X.
# 2
