class Solution:
    def canCross(self, stones: List[int]) -> bool:

        # Memoize dead-ends, DFS
        target, stones = stones[-1], set(stones)
        memo = set()
        def dfs(pos, jump):
            if (pos, jump) in memo:
                return False
            if pos == target:
                return True
            if jump <= 0 or pos not in stones:
                return False
            for j in (jump-1, jump, jump+1):
                if dfs(pos+j, j):
                    return True
            memo.add((pos, jump))
            return False

        return dfs(1, 1)

        
