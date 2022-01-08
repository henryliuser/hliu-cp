# https://codeforces.com/problemset/problem/1617/D1
# 1. if 1 known player, we can query if a pair contains an imposter
# 2. if know 1 imp, 1 crew, can query identity of any player
# 3. if we can find 1 imp, 1 crew in N+2 queries, we have solution
# 4. if we know whether pairs have 1 imposter or not, we need only
#        target those pairs when we sweep at the end
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(a, b, c):
    print('?', a, b, c)
    sys.stdout.flush()
    x, = intput()
    if x == -1: exit()
    return x

def submit(A):
    print('!', len(A), *A)
    sys.stdout.flush()

def caseDiff(res):  # solve for case where p1 and p2 are different
    ans = set()
    crew = imp = -1
    for i,k in res.values():
        if k == 1: crew = i
        if k == 0:
            imp = i
            ans.add(i)
    one = query(crew, imp, 1)
    if one == 1: ans.add(2)
    if one == 0: ans.add(1)
    return ans

def edge(c):
    a = query(1, 3, 5)
    if c == "crew" and a == 0: return 1,3
    if c ==  "imp" and a == 1: return 3,1
    b = query(1, 3, 6)
    if c == "crew":




def caseSame(c):
    crew = imp = -1
    res, ans = {}, set()
    if c == "imp": ans |= {1,2}
    k = N-1 // 2
    for i in range(k):
        j = i*2+3
        if j >= N: j -= 1
        r = query(1, j, j+1)
        res[ (j,j+1) ] = r
        if c == "imp" and r == 1:
            imp, crew = 1, j
            break
        if c == "crew" and r == 0:
            crew, imp = 1, j
            break
    else:
        edge(c)
        # handle hard case


        # edit res

    for (i,j), r in res:
        x = query(crew, imp, i)
        if x == 0: ans.add(i)
        if x == 1: ans.add(j)
    return ans



def solve():
    res, cnt = {}, [0,0]
    for i in range(N*2//3):
        r = query(1, 2, i+3)
        res[r] += 1
        res[i+3] = r
    if cnt[0] > 0 and cnt[1] > 0:
        ans = caseDiff(res)
    else:
        c = "crew" if cnt[0] == 0 else "imp"
        ans = caseSame(c)

    submit(ans)


if __name__ == '__main__':
    t, = intput()
    for _ in range(t):
        solve()
