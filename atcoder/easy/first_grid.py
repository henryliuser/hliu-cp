def solve():
    grid = [input(), input()]
    return 'No' if grid in [["#.", ".#"], [".#", "#."]] else 'Yes'

print( solve() )
