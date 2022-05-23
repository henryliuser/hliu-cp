# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        L = []
        curr = head
        while curr:
            L.append(curr)
            curr = curr.next
        N = len(L)
        for i in range(N // 2):
            L[i].next = L[~i]
            L[~i].next = L[i+1]
        L[N//2].next = None
        
