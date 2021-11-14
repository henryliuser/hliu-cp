class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        ans = 0
        N = len(tickets)
        while True:
            for j in range(N):
                if tickets[j] == 0: continue
                ans += 1
                tickets[j] -= 1
                if j == k and tickets[j] == 0:
                    return ans
