class Solution:
    def wateringPlants(self, plants: List[int], cap: int) -> int:
        ans = 0
        N = len(plants)
        curr = cap
        for i in range(N):
            ans += 1
            curr -= plants[i]
            if i + 1 < N and curr < plants[i+1]:
                ans += 2*(i+1)
                curr = cap
        return ans
            
