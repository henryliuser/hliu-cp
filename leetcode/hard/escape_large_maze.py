class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        dirs = ((0,1), (1,0), (-1,-1), (1,-1),
                (0,-1), (-1,0), (1,1), (-1,1))

        def addCX(x, y):
            chainX[x][0] = min(chainX[x][0], y)
            chainX[x][1] = max(chainX[x][1], y)
        def addCY(x, y):
            chainY[y][0] = min(chainY[y][0], x)
            chainY[y][1] = max(chainY[y][1], x)

        def contained(x, y):
            ya, yb = chainX
            xa, xb = chainY
            return ya <= y <= yb and xa <= x <= xb

        def dfs(x, y):
            addCX(x, y), addCY(x, y)
            seen.add( (x,y) )
            for d in dirs:
                r, c = x+d[0], y+d[1]
                if (r,c) in obs and (r,c) not in seen:
                    dfs(r, c)

        # if # of blocks NOT limited to 200:
        # maintain running region
        # if (x,y) in seen
        #   region = list[idx[seen] : -1]
        #   check if src/target contained,
        # count number of regions containing src/target
        # if they match then true
        # 2 axis hits: axes become bounds

        seen = set()
        sx, sy = source
        tx, ty = target
        obs = set(tuple(b) for b in blocked)
        for x,y in blocked:
            chainX = defaultdict(lambda: [float('inf'), -float('inf')])
            chainY = defaultdict(lambda: [float('inf'), -float('inf')])
            dfs(x,y)
            if contained(sx, sy) and not contained(tx, ty):
                return False
