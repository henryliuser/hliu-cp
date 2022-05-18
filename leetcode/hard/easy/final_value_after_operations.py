class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if o.find('+') != -1 else -1 for o in operations)

        # d = {'++X':1, 'X++':1, '--X':-1, 'X--':-1}
        # ans = 0
        # for o in operations:
        #     ans += d[o]
        # return ans
