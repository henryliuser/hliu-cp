# [[0,1],[0,2],[2,3],[3,4],[3,5],[5,6],[2,7],[6,7],[7,8],[3,8],[5,8],[8,9],[3,9],[6,9]]
# "nnllnzznn"
# "aabbaccaa"
# [[0,1],[1,2],[2,3],[2,4],[3,5],[4,6],[3,6],[5,6],[6,7],[7,8]]
s = input()
L = eval(s)
for a,b in L:
    print(a,b)
