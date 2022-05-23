# https://leetcode.com/contest/weekly-contest-294/problems/sum-of-total-strength-of-wizards/
# great question, got 3 solutions

# O(N) monostack + prefix sum of prefix sum
# compute ple and nleq: prev/next lesser element (q : lesser or equal)
# basically, do some math/experiments and realize that
# l,r = ple[i]+1, nleq[i]-1
# R = (psps[r+1] - psps[i]) * (i-l+1)
# L = (psps[i-1] - psps[l]) * (r-i+1)
# ans += A[i] * (R-L)
class Solution:
    def totalStrength(self, A: List[int]) -> int:
        N = len(A)
        Q = int(1e9)+7

        # monostack
        # ple[i] = prev lesser element, than the one at i
        # nle[i] = next lesser element
        ple, nleq = [-1]*N, [N]*N
        def mono(L, leq, loop, st=[]):
            for i in loop:
                while st and A[i] < A[st[-1]]+leq:
                    L[st.pop()] = i
                st += [i]
        mono(nleq, 1, range(N))
        mono(ple, 0, range(N-1,-1,-1))

        # {ps: prefix sum of A}  {dp: prefix sum of ps}
        ps, dp = [0]*(N+1), [0]*(N+1)
        for i in range(N):
            ps[i+1] = A[i] + ps[i]
            dp[i+1] = ps[i+1] + dp[i]

        ans = 0
        for i in range(N):
            l, r = ple[i]+1, nleq[i]-1
            L = (dp[i]-dp[max(0,l-1)]) * (r-i+1) % Q
            R = (dp[r+1]-dp[i]) * (i-l+1) % Q
            z = A[i] * (R-L) % Q
            ans = (ans + z) % Q

        return ans


# O(N) monostack + double dp + prefix sum + prefix sum of prefix sum
# Not a good solution, but it's cool and it's the first one i came up with.
# this one solves it from the angle of:
# what's the cost (sum of strength) of all the subarrays that end at i?
# and sum across all i
#
# ple[i] = index of previous lesser element than the one at A[i]
#
# dp1[i] = sum( suffixMin( A[0...i] ) )
#        = sum of the running min going backwards from A[i] to A[0]
# ex: A = [1,3,2,5,4]
# dp1[3] = sum( suffixMin = [1,2,2,5] ) = 1+2+2+5 = 10
# dp1[1] = sum( suffixMin = [1,3] ) = 1+3 = 4
#
# query(i, j) -> sum of all the subarrays with:
#      RIGHT bound == i,
#       LEFT bound >= j
# ex: A = [1,3,2,5,4]
# query(1, 3) = (3+2+5) + (2+5) + (5)
#
# dp2[i] = cost of all subarrays ending at i
# dp2[i] = RIGHT + LEFT
#     j = ple[i]
#     RIGHT: cost of subarrays ending at i where i is the minimum
#     RIGHT = A[i] * query(i, j+1)
#
#      LEFT: cost of subarrays ending at i where i is NOT the minimum
#      LEFT = dp2[j] + dp1[j] * sum(A[j+1 ... i])
#
# ans = sum(dp2)
class Solution:
    def totalStrength(self, A: List[int]) -> int:
        N = len(A)
        Q = int(1e9)+7

        # monostack
        # ple[i] = previous lesser element, than the one at i
        st, ple = [], [-1]*N
        for i in range(N-1,-1,-1):
            while st and A[st[-1]] > A[i]:
                ple[st.pop()] = i
            st += [i]

        # preprocessing
        ps = [0] * (N+1)   # suffix sum
        ds = [0] * (N+1)   # suffix sum of suffix sum
        dp1 = [0] * (N+1)  # dp1[i] = sum( suffixMin of A[0..i] )
        for z in range(N):
            i, j = ~z-1, ~z
            ps[i] = A[j] + ps[j]
            ds[i] = ps[i] + ds[j]
            k = ple[z]
            dp1[z] = A[z] * (z-k)
            if k != -1: dp1[z] += dp1[k]

        def query(i, j):  # -> sum( sum(A[i..k] for k in range(j, i) )
            if i < j: return 0
            diff = ds[j] - ds[i+1]
            chop = ps[i+1]
            size = i-j+1
            return diff - chop * size

        ans = 0
        dp2 = [0] * (N+1)
        for i in range(N):
            j = ple[i] + 1
            x = A[i] * query(i, j) % Q
            if j == 0: y = 0
            else:
                m = dp1[j-1]
                s = ps[j] - ps[i+1]
                y = (dp2[j-1] + m*s % Q) % Q
            dp2[i] = (x + y) % Q
            ans = (ans + dp2[i]) % Q

        return ans


# another one just for completeness
# O(N) with monostack, basically same as first one,
# but less clever and more monke:
# sq(i, j) gives:
#   if (i < j) -> (A[i]) + (A[i] + A[i+1]) + ... + (A[i]+A[i+1]+A[i+2]+...+A[j])
#   if (i > j) -> (A[i]) + (A[i] + A[i-1]) + ... + (A[i]+A[i-1]+A[i-2]+...+A[j])
# then:
# l, r = ple[i]+1, nleq[i]-1
# L = sq(i-1, l) * (r-i+1)
# R = sq( i, r ) * (i-l+1)
# ans += A[i] * (L+R)
class SumQuery:
    def __init__(self, A):
        N = len(A) + 1
        d = [[0]*N, [0]*N]
        p = [[0]*N, [0]*N]
        for i in range(1,N):
            d[0][i] = A[i-1] + d[0][i-1]
            d[1][~i] = A[-i] + d[1][N-i]
            p[0][i] = d[0][i] + p[0][i-1]
            p[1][~i] = d[1][~i] + p[1][N-i]
        self.d, self.p = d, p
    def __call__(self, src, dst):
        q = src > dst
        if q: src += 1
        else: dst += 1
        d, p = self.d, self.p
        q = int(src > dst)
        diff = p[q][dst] - p[q][src]
        chop = d[q][src]
        size = abs(dst-src)
        return diff - chop * size

class Solution:
    def totalStrength(self, A: List[int]) -> int:
        N = len(A)
        Q = int(1e9)+7

        # monostack
        # ple[i] = prev lesser element, than the one at i
        # nle[i] = next lesser element
        ple, nleq = [-1]*N, [N]*N
        def mono(L, leq, loop, st=[]):
            for i in loop:
                while st and A[i] < A[st[-1]]+leq:
                    L[st.pop()] = i
                st += [i]
        mono(nleq, 1, range(N))
        mono(ple, 0, range(N-1,-1,-1))

        ans = 0
        sq = SumQuery(A)
        for i in range(N):
            l, r = ple[i]+1, nleq[i]-1
            x = 0 if i-1 < l else sq(i-1, l) * (r-i+1) % Q
            y = 0 if  i > r  else  sq(i, r)  * (i-l+1) % Q
            z = A[i] * (x + y) % Q
            ans = (ans + z) % Q

        return ans
