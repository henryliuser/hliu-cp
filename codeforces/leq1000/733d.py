# D. Secret Santa
from collections import defaultdict
t = int(input())
def solve():
    ans = [0, []]
    n = int(input())
    wish = list(map(int, input().split()))
    sets = defaultdict(list)
    taken = set()
    free = set(range(1, n+1))
    for i, w in enumerate(wish, start=1):
        sets[w].append(i)
        if w in free:
            free.remove(w)
            ans[0] += 1
    fr2 = list(free)
    for w in wish:
        if w not in taken:
            ans[1].append(w)
            taken.add(w)
        else:
            ans[1].append(fr2.pop(-1))
    # print(ans[1])
    for i, w in enumerate(ans[1], start=1):
        if i == w:
            # print(sets[wish[i-1]])
            for x in sets[wish[i-1]]:
                if x != i:
                    # print(i-1, x-1)
                    ans[1][i-1], ans[1][x-1] = ans[1][x-1], ans[1][i-1]
                    break
    return ans

for _ in range(t):
    s = solve()
    print(f"{s[0]}\n{' '.join(map(str, s[1]))}")
