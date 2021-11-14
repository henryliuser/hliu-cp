# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None
        groups = []
        curr = head.next
        i, num, L = 0, 2, []
        while curr:
            L.append(curr)
            curr = curr.next
            i += 1
            if i == num:
                groups.append(L)
                i, num, L = 0, num+1, []
        groups.append(L)
        for i,g in enumerate(groups):
            if len(g) % 2 == 0:
                groups[i] = g[::-1]

        curr = head
        for i,g in enumerate(groups):
            for j,node in enumerate(g):
                curr.next = node
                curr = node
                curr.next = None

        return head



            
