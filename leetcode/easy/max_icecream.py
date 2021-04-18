class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs = sorted(costs)
        ans = 0
        for x in range(len(costs)):
            coins -= costs[x]
            if coins >= 0: ans += 1
        return ans
        
