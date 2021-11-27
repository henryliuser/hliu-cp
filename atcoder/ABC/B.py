def solve():
    A,B = input().split()
    for a,b in zip(A[::-1], B[::-1]):
        if int(a) + int(b) > 9:
            return 'Hard'
    return 'Easy'

print( solve() )
