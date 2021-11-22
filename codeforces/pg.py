def dfs(a,b,x,depth):
    if depth == 5: return
    print(a,b)
    dfs(abs(a-b), b, x, depth+1)
    dfs(a, abs(a-b), x, depth+1)

dfs(6,9,3,0)
