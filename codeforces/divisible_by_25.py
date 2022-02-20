import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    S = input()
    N = len(S)
    f = S[0]
    if f == "0": return 0
    d = S[:-2]
    spec = ["_", "X"]
    const = {"25", "50", "75", "00"}
    if d in const:
        if f not in spec:
            ans = 1
            for i in range(N-2):
                if S[i] == '_':
                    ans *= 10
            if "X" in S:
                ans *= 10
            return ans
        if f == "_":
            ans = 9
            for i in range(1, N-2):
                if S[i] == '_':
                    ans *= 10
            if "X" in S:
                ans *= 10
            return ans
        if f == "X":
            ans = 9
            for i in range(1, N-2):
                if S[i] == '_':
                    ans *= 10
            return ans
    


if __name__ == '__main__':
    print( solve() )
