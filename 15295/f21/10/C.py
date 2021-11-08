def subseq(a, b):  # a is subseq of b
    i = j = 0
    while True:
        if i >= len(a): return True
        if j >= len(b): return False
        if a[i] == b[j]:
            i += 1
        j += 1

def solve():
    s, t = input(), input()
    if subseq(t, s): return "automaton"
    s, t = sorted(s), sorted(t)
    if s == t: return "array"
    if subseq(t, s): return "both"
    return "need tree"

print( solve() )
