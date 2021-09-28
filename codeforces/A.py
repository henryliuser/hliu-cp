from collections import Counter
def solve():
    c = Counter(input())
    yes =  c['A'] + c['C'] == c['B']
    if yes: return "YES"
    return "NO"


t = int(input())

for _ in range(t):
    print( solve() )
