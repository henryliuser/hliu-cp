class Solution:
     def memLeak(self, mem1: int, mem2: int) -> List[int]:
        leaking = 1
        while mem1 >= leaking or mem2 >= leaking:
            if mem1 < mem2:
                mem2 -= leaking
            else:
                mem1 -= leaking
            leaking += 1
        return [leaking, mem1, mem2]
        
