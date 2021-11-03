# s = ""
#
# while 3:
#     s = input().split()
#     try:
#         int(s[0])
#         s = s[1:]
#     except: pass
#     print(' '.join(s))
# ans = 0
# N = 5
# def dfs(i, x):
#     global ans
#     if i == N-1:
#         ans += 1
#         return
#     for j in [x-1, x, x+1]:
#         if 0 < j <= 10:
#             dfs(i+1, j)
#
# for i in range(1, 11):
#     dfs(0, i)
#
# print(ans)

g = {...}
def getPrereqs(g, course):
    prereqs = []
    for k in g:
        if course in g[k]:
            prereqs.append(k)
    return prereqs



def findParents(t, name):
    c = t['content']
    L, R = t['left'], t['right']
    if c == name:
        parents = []
        if L != None: parents.append(L['content'])
        if R != None: parents.append(R['content'])
        return parents
    if L == None and R == None:
        return None
    fl = findParents(L, name)
    if fl != None: return fl
    return findParent(R, name)
