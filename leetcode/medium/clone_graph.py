from queue import Queue
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return
        copy = Node(node.val)
        q = Queue()
        q.put( (copy, node) )
        seen = {copy.val:copy}
        while not q.empty():
            cp, og = q.get()
            for n in og.neighbors:
                if n.val in seen:
                    cp.neighbors.append(seen[n.val])
                else:
                    temp = Node(n.val)
                    cp.neighbors.append(temp)
                    seen[n.val] = temp
                    q.put( (temp, n) )
        return copy
