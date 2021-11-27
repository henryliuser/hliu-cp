def solve():
    grid = [input(), input()]
    if grid == ["#.", ".#"]:
        return 'No'
    if grid == [".#", "#."]:
        return 'No'
    return 'Yes'

print( solve() )
