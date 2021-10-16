def largestEdge(g):
    ans = 0
    best = None
    for node1 in g:
        for node2, weight in g[node1]:
            if weight > ans:
                ans = weight
                best = [node1, node2]
    return best


L  = [0] * 5  # [0,0,0,0,0]
L2 = [[0] * 5 for i in range(5) if i != 3]
print(L2)

# ans = []
# for i in range(len(L)):
#     for j in range(len(L[i])):
#         x = L[i][j]
#         if x > 0:
#             ans.append(x)
# return ans

# return [x for y in L for x in y if x > 0]
