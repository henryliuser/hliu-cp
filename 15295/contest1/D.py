def solve():
    N, Q = map(int, input().split())
    s = input()
    pre = [0]
    alt = 1
    for ch in s:
        if ch == '+': pre.append(pre[-1] + alt * 1)
        else:         pre.append(pre[-1] + alt * -1)
        alt = -alt
    print(pre)
    for _ in range(Q):
        a, b = map(int, input().split())
        
        print(abs(pre[b] - pre[a-1]))

T = int(input())
for _ in range(T):
    solve()
