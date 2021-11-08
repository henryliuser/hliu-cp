intput = lambda : map(int, input().split())

def solve():
    ans = 0
    S = list(input())
    for i in range(len(S)):
        for j in range(max(0, i-2), min(len(S),i+1)):
            if i == j: continue
            if S[i] == S[j]:
                S[i] = '@'
                ans += 1
                break
    return ans


T, = intput()
for _ in range(T):
    print(solve())
