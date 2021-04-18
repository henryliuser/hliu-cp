# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def solve(self, head, pos, val):
        count = 0
        ans = head
        if pos == 0:
            return LLNode(val, head)
        while head:
            if count+1 == pos:
                new = LLNode(val, head.next)
                head.next = new
                break
            head = head.next
            count += 1

        return ans
