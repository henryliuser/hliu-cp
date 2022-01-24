import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def dfsA(i, cs, cn):  # average
    if i >= N:
        return 0,100
    if dpA[i][0] != -1:
        return dpA[i][1:]

    res = [0, 0, 0]
    # take it
    r1, r2 = dfsA(i+1, cs+A[i], cn+1)
    r1 += A[i]
    r2 += 1
    nav = r1/r2
    if nav > res[0]:


    # don't take
    if i+1 < N:
        dfsA(i+2, cs+A[i+1], cn+1)
    # else:
    #     avg = max(avg, cs/cn)

    dpA[i] = res
    return res[1:]

if __name__ == '__main__':
    N,  = intput()
    A   = list(intput())
    avg = med = 0
    dpA = [[-1,0,0] for _ in range(N)]  # [avg, sum, len]
    dpM = []

    dfsA(0, 0, 0)
    print(avg)
    # res[1] += cs
    # res[2] += cn
    # res[0] = res[1] / res[2]

    # for r in dpA: print(r)
