class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = set(map(tuple, obstacles))
        x, y = 0, 0
        ans = 0
        dir = 0 # 0:north, 1: east, 2:south, 3:west
        for c in commands:
            if c < 0:
                if c == -2: dir = (dir-1) % 4
                if c == -1: dir = (dir+1) % 4
            else:
                for z in range(c):
                    ax, ay = x, y
                    if dir == 0: y += 1
                    if dir == 1: x += 1
                    if dir == 2: y -= 1
                    if dir == 3: x -= 1
                    if (x, y) in obs:
                        x,y = ax, ay
                        break
            ans = max(ans, x*x+y*y)
        return ans

            
