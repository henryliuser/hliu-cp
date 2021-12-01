import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, Q = intput()
    abc = ['a', 'b', 'c']
    S = list(input())
    N = len(S)

    count = 0
    for i in range(N-2):
        if S[i] != 'a': continue
        if S[i:i+3] == abc:
            count += 1

    def check(x, p):
        if x == 'a': i, j = p, p+3
        if x == 'b': i, j = p-1, p+2
        if x == 'c': i, j = p-2, p+1
        return (max(0, i), min(N, j))

    for q in range(Q):
        p, x = input().split()
        p = int(p) - 1
        i, j = check(S[p], p)
        if S[i:j] == abc:
            count -= 1
        i, j = check(x, p)
        S[p] = x
        if S[i:j] == abc:
            count += 1
        # print("".join(S))
        print(count)
