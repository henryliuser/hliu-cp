from random import randrange
class RandomizedCollection:
    def __init__(self):
        self.d = defaultdict(set)
        self.l = []

    def insert(self, val: int) -> bool:
        f = val not in self.d
        self.l.append(val)
        self.d[val].add(len(self.l)-1)
        return f

    def remove(self, val: int) -> bool:
        if val not in self.d: return False
        last = self.l[-1]
        vidx = self.d[val].pop()
        if len(self.d[val]) == 0:
            self.d.pop(val)

        self.d[last].add(vidx)
        self.d[last].remove(len(self.l)-1)
        if len(self.d[last]) == 0:
            self.d.pop(val)
        self.l[vidx], self.l[-1] = self.l[-1], self.l[vidx]
        self.l.pop()
        return True

    def getRandom(self) -> int:
        return self.l[randrange(0, len(self.l))]



# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
