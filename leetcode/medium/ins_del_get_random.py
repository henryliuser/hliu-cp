from random import randrange
class RandomizedSet:

    def __init__(self):
        self.d = {}
        self.l = []

    def insert(self, val: int) -> bool:
        if val in self.d: return False
        self.l.append(val)
        self.d[val] = len(self.l)-1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.d: return False
        idx = self.d[val]
        self.d[self.l[-1]] = idx
        self.d.pop(val)
        self.l[idx], self.l[-1] = self.l[-1], self.l[idx]
        self.l.pop()
        return True

    def getRandom(self) -> int:
        return self.l[randrange(0, len(self.l))]



# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
