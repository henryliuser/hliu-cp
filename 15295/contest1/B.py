def run():
    dirs = {'L':(-1,0), 'R':(1,0), 'U':(0,1), 'D':(0,-1)}
    d2 = ((1,0), (0,1), (-1,0), (0,-1))
    x = y = 0
    seen = {(0,0)}
    adj = set()
    ins = input()
    prev = (0,0)
    for i,s in enumerate(ins):
        d = dirs[s]
        x, y = x+d[0], y+d[1]
        if (x,y) in seen or (x,y) in adj:
            return "BUG"
        seen.add((x,y))
        for D in d2:
            r,c = prev
            r,c = r+D[0], c+D[1]
            adj.add((r,c))
        prev = (x,y)
    return "OK"

print(run())
