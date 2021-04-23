class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:

        # one-liner
        return reduce(lambda x,y: x^y, arr1) & reduce(lambda x,y: x^y, arr2)

        # distributive property of xor
        xor1, xor2 = arr1[0], arr2[0]
        for x in range(1, len(arr1)): xor1 ^= arr1[x]
        for x in range(1, len(arr2)): xor2 ^= arr2[x]
        return xor1 & xor2

        # literal, TLE
        thelist = []
        for x in arr1:
            for y in arr2:
                thelist.append(x & y)
        xor = thelist[0]
        # print(thelist)
        for x in range(1, len(thelist)):
            xor ^= thelist[x]
        return xor
