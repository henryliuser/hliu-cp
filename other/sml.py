from functools import reduce
# def RoseFoldL(f, z, x, rs):
#     if rs == []: return f(z,x)
#     for r in rs:
#         RoseFoldL(f, ?, r.x, r.rs)
class Rose:
    def __init__(self, x):
        self.x = x
        self.rs = []

def roseFoldl(f, z, r):
    b = f(z, r.x)
    for q in r.rs:
        b = roseFoldl(f, b, q)
    return b

# def dfs2(f, z, r):
    # b = f(z, r.x)
    # if r.rs == []: return b
    # return reduce(f, map(lambda p : dfs(f,b,p), r.rs))

r = Rose('1')
r.rs = [Rose('2'), Rose('3'), Rose('4')]
r.rs[0].rs = [Rose('5')]
r.rs[2].rs = [Rose('6'), Rose('7')]

concat = lambda a,b : a + b
print( roseFoldl(concat, '3', r) )



# fun roseFoldl (f, z, (x,[]) ) = f(z,x)
# fun roseFoldl (f, z, (x,rs) ) =
#     let
#         val c = f(z,x)
#     in
#         foldl (map roseFoldl f c rs) c
