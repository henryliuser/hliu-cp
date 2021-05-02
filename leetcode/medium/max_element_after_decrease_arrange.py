class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        ans = 0
        for x in range(len(arr)):
            if x == 0: arr[x] = 1
            else:
                if arr[x] > arr[x-1]:
                    arr[x] = arr[x-1] + 1
                elif arr[x] == arr[x-1]: pass
        return arr[-1]
            
