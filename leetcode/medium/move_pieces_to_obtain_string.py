# https://leetcode.com/contest/weekly-contest-301/submissions/detail/743088687/

# functional
# editorial: https://leetcode.com/problems/move-pieces-to-obtain-a-string/discuss/2261792/5-Lines-Very-Elegant-Functional-Solution-(Python)
class Solution:
    def canChange(self, A: str, B: str) -> bool:
        P = lambda c    :  c != '_'
        I = lambda s,x  :  [i for i,c in enumerate(s) if c==x]
        G = lambda d,p  :  all( p(x,y) for x,y in zip( I(A,d), I(B,d) ) )
        S = lambda      :  [*filter(P,A)] == [*filter(P,B)]
        return S() and G('L', ge) and G('R', le)


# 2 pointers, imperative
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        i = 0
        N = len(start)

        for j in range(N):
            if target[j] == '_': continue
            while i < N and start[i] == '_': i += 1
            if i >= N: return False
            ch = target[j]
            if start[i] != target[j]: return False
            if ch == 'R' and i > j: return False
            if ch == 'L' and i < j: return False
            i += 1

        for x in range(i, N):
            if start[x] != '_': return False

        return True



# bad way
class Solution:
    def canChange(self, A: str, B: str) -> bool:
        p = lambda c : c != '_'
        ans = [*filter(p, A)] == [*filter(p, B)]
        where = lambda s,x : [i for i,c in enumerate(s) if c==x]

        for d,p in zip( "LR", [lt,gt] ):
            occS = where(A, d)
            occT = where(B, d)
            ans &= not any( p(x,y) for x,y in zip(occS, occT) )
        return ans
