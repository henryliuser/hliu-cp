# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:

        # O(N) time, O(1) memory
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True
        return False

        # O(N) time, O(1) memory
        if not head: return False
        slow, fast = head, head.next
        while slow is not fast:
            try:
                slow = slow.next
                fast = fast.next.next
            except:
                return False
        return True

        # O(N) time, O(N) memory
        s = set()
        while head:
            i = id(head)
            if i in s: return True
            s.add(id(head))
            head = head.next
        return False
