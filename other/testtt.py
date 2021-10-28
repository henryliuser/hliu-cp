def fp(A, pl, pr):
    def dfs(L, R, c):
        if c == len(A):
            print(f"L: {L}")
            print(f"R: {R}")
            # rl, rr = pl(L), pr(r)
            # if rl and rr:
            #     return rl, rr
            return None
        L.append(A[c])
        rl = dfs(L, R, c+1)
        if rl: return rl
        R.append(L.pop())
        rr = dfs(L, R, c+1)
        if rr: return rr
        R.pop()
    dfs([], [], 0)

A = [0,1,2,3,4,5,6,7,8,9]
fp(A, lambda x:x, lambda x:x)
