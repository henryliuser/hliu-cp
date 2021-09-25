class Solution:
    # great problem. sort, then monostack on the indices.
    # can improve by using iterative dp instead of dfs
    def oddEvenJumps(self, arr: List[int]) -> int:
        N = len(arr)
        less = sorted(range(N), key=lambda x: -arr[x])
        more = sorted(range(N), key=lambda x:  arr[x])
        ngeq = [-1] * N
        nleq = [-1] * N
        def process(res, src):
            st = []
            for i,x in enumerate(src):
                while st and x > src[st[-1][0]]:
                    a,b = st.pop()
                    res[b] = x
                st.append((i,x))

        process(nleq, less)
        process(ngeq, more)

        dp = [[-1] * N for _ in range(2)]
        def dfs(x, odd):
            if x == N-1: return 1
            o = int(odd)
            if dp[o][x] != -1: return dp[o][x]
            if odd:
                if ngeq[x] == -1: dp[o][x] = 0
                else: dp[o][x] = dfs(ngeq[x], not odd)
            else:
                if nleq[x] == -1: dp[o][x] = 0
                else: dp[o][x] = dfs(nleq[x], not odd)
            return dp[o][x]

        ans = 0
        for i in range(N):
            ans += dfs(i, True)
        return ans
