# https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

# O(ans), intuitive
class Solution:
    def fillCups(self, A: List[int]) -> int:
        ans = 0
        while not all(x <= 0 for x in A):
            A.sort()
            A[1] -= 1
            A[2] -= 1
            ans += 1
        return ans

# O(N)
class Solution:
    def fillCups(self, A : List[int]) -> int:
        return max( max(A), (sum(A)+1)//2 )
