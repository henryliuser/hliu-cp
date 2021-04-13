# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        # string to int and sum and back
        # num1 = num2 = []
        def toInt(head):
            L = []
            while head:
                L.append(str(head.val))
                head = head.next
            return int("".join(L[::-1]))
        def toLinkedList(num):
            L = ListNode(0)
            head = L
            while num > 9:
                L.next = ListNode(num % 10)
                num //= 10
                L = L.next
            L.next = ListNode(num)
            return head.next
        return toLinkedList(toInt(l1) + toInt(l2))

        # pure LinkedList processing and math
        ans = ListNode(0)
        head = ans
        carry = 0
        while l1 and l2:
            curr = l1.val + l2.val + carry
            if curr > 9:
                carry = curr // 10
                curr %= 10
            else: carry = 0
            ans.next = ListNode(curr)
            ans = ans.next
            l1, l2 = l1.next, l2.next

        if   l1: t = l1  # t is whichever one is left over
        elif l2: t = l2
        elif carry > 0:
            ans.next = ListNode(carry)
            return head.next
        else: return head.next

        while t:
            curr = t.val + carry
            if curr > 9:
                carry = curr // 10
                curr %= 10
            else: carry = 0
            ans.next = ListNode(curr)
            ans = ans.next
            t = t.next

        if carry > 0: ans.next = ListNode(carry)
        return head.next
