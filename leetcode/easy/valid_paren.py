class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        openers = {'(':')', '{':'}', '[':']'}
        for ch in s:
            if ch in openers:
                stack.append(ch)
            else:
                if len(stack) < 1: return False
                if ch != openers[stack[-1]]:
                    return False
                stack.pop(-1)
        return len(stack) == 0
