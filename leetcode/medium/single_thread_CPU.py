import heapq
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        if not tasks: return []
        for x in range(len(tasks)): tasks[x].append(x)
        tasks.sort(key=lambda x: x[0])
        heapq.heapify(pq := [])
        ans = []
        t = tasks[0][0]

        c = 0  # tasks counter
        while len(ans) < len(tasks): # while not done
            while c < len(tasks) and t >= tasks[c][0]:
                task = tasks[c]
                heapq.heappush(pq, (task[1], task[2]) )
                c += 1
            if pq:
                tk = heapq.heappop(pq)
                ans.append(tk[1])
                t += tk[0]
            elif c < len(tasks) and t < tasks[c][0]:
                # must be elif here or else WA
                t = tasks[c][0]

        return ans
