# O(MN) prime hashing
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        PRIMES = [2, 3, 5, 7, 11 ,13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47, 53, 59, 61, 67,
                  71, 73, 79, 83, 89, 97, 101, 107]
        anagrams = defaultdict(list)
        for s in strs:
            h = 1  # prime hash
            for ch in s:
                idx = ord(ch) - ord('a')
                h *= PRIMES[idx]
            anagrams[h].append(s)
        return anagrams.values()

# O(MN log N) sorting
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for s in strs:
            anagrams["".join(sorted(s))].append(s)
        return anagrams.values()
