# https://leetcode.com/contest/weekly-contest-301/submissions/detail/743088687/

# 2 pointers
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


# functional
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        p = lambda c : c != '_'
        ans = [*filter(p, start)] == [*filter(p, target)]
        where = lambda A,x : [i for i,c in enumerate(A) if c==x]

        for d,p in zip( "LR", [lt,gt] ):
            occS = where( start,  d )
            occT = where( target, d )
            ans &= not any( p(*z) for z in zip(occS, occT) )
        return ans
