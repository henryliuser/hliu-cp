intput = lambda : map(int, input().split())
n, k = intput()
arr = list(intput())
def solve():
    if k == 1: return min(arr)
    if k == 2:
        pre, suf = [arr[0]], [arr[-1]]
        for i in range(1, n):
            pre.append(min(pre[-1], arr[i]))
            suf.append(min(suf[-1], arr[~i]))
        return max(max(pre[i], suf[~i-1]) for i in range(n-1))
    else: return max(arr)

print(solve())
