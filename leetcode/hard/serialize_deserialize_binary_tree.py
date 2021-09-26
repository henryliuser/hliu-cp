# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        if not root: return ""
        def dfs(root, st) -> [(int, int)]:
            V = root.val
            L, R = root.left, root.right
            if not L and not R:
                st.append((2, V))
            if L and not R:
                st.append((1, V))
                dfs(L, st)
                st.append((0, 0))
            if R and not L:
                st.append((1, V))
                st.append((0, 0))
                dfs(R, st)
            if L and R:
                st.append((1, V))
                dfs(L, st)
                dfs(R, st)
            return st

        il = dfs(root, [])
        cvt = lambda t : f"{t[0]}/{t[1]}"  # q0/v0,q1/v1,q2/v2
        return ','.join(map(cvt, il))


    def deserialize(self, data):
        if not data: return None
        il = data.split(',')
        N = len(il)

        def cvt(s: int) -> (int, int):
            parts = s.split('/')
            return map(int, parts)

        def dfs(idx: int) -> (TreeNode, int):
            q,v = cvt(il[idx])
            t = TreeNode(v)
            nxt = idx + 1
            if q == 0: t = None
            if q == 1:
                l, r = il[idx+1], il[idx+2]
                ql, vl = cvt(l)
                qr, vr = cvt(r)
                l, r = TreeNode(vl), TreeNode(vr)
                if   (ql, qr) == (2, 2):
                    t.left, t.right = l, r
                    nxt += 2
                elif (ql, qr) == (0, 2):
                    t.right = r
                    nxt += 2
                elif (ql, qr) == (2, 0):
                    t.left = l
                    nxt += 2
                elif (ql, qr) == (0, 1):
                    t.right, nxt = dfs(nxt+1)
                else:
                    a,b = dfs(idx+1)
                    c,d = dfs(b)
                    t.left, t.right = a, c
                    nxt = d
            return (t, nxt)

        root, z = dfs(0)
        return root
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
