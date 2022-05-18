class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return set(s.lower() for s in sentence) == set("abcdefghijklmnopqrstuvwxyz")
