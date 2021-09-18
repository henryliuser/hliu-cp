def asd():
    x = int(input())
    if x >= 90: return 'expert'
    if x >= 70: return 90 - x
    if x >= 40: return 70 - x
    return 40 - x
print(asd())
