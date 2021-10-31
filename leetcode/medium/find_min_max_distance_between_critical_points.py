# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        i = 0  # index
        crits = []
        curr = head
        prev = None
        while curr.next:
            if prev and prev.val < curr.val > curr.next.val:
                crits.append(i)
            elif prev and prev.val > curr.val < curr.next.val:
                crits.append(i)
            i += 1
            prev = curr
            curr = curr.next

        nc = len(crits)
        if nc < 2: return [-1, -1]
        mx = crits[-1] - crits[0]  # max dist
        mn = float('inf')
        for i in range(1, len(crits)):
            mn = min(mn, crits[i]-crits[i-1])
        return [mn, mx]
                
