# https://codeforces.com/contest/1641/problem/B
# enormous observation required, but pretty cool
# we want to arrange the original array A s.t. it becomes a tandem repeat
# it turns out, you can reverse any prefix, length K, in K operations
# abcdbdca -> rev(3) -> abc[abccba]dbdca -> new prefix of length 2k is tandem
# so the part we're worried about now is abcabc[cbadbdca]
# what we've effectively accomplished is reversing a length k prefix in A
# and we just want to repeatedly do that until A itself becomes tandem
# abcabc[cbadbdca] -> we want xxx...xx[abcdabcd]
# (the section of x's is a tandem repeat.)
# strategy: sort the characters in A with occurrences/2
# abcdbdca -> abcd, then the tandem is just itself concatenated with itself
# target: abcdabcd. we can move each final character in place in 2 rev's
# abcdbdca -> rev(4) -> dcbabdca -> rev(8) -> acdbabcd
# acdbabcd, 2nd half already sorted now.
# -> rev(3) -> dcababcd -> rev(4) -> bacdabcd
# -> rev(2) -> abcdabcd
# rev(K) requires K operations so it runs in O(K)
# total complexity O(N^2)
import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right

# FASTIO
import os, sys
from io import BytesIO, IOBase
BUFSIZE: int = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b: break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
def print(*args, **kwargs):
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
intput = lambda : map(int, input().split())
# END FASTIO

def solve():
    N, = intput()
    A = [*intput()]
    cnt = Counter(A)
    guard = cnt.values()
    if any(c%2 for c in guard): return []


    B = []
    S = sorted(A)
    for i in range(0, N, 2):
        B += [ S[i] ]
    B = B+B

    G = 0
    ops = []
    splits = []
    def rev(k):  # reverse the prefix of length k
        nonlocal G, ops, splits
        for i in range(k):
            p = k+G+i
            c = A[i]
            ops += [ (p,c) ]

        for i in range(k//2):
            A[i], A[~i+k] = A[~i+k], A[i]

        sz = 2*k
        G += sz
        splits += [ (sz,) ]  # tuple for printing lol

    for j in range(N-1, 0, -1):
        if A[j] == B[j]: continue
        if A[0] == B[j]:
            rev(j+1)
        else:
            q = A.index(B[j])
            rev(q+1)
            rev(j+1)

    q = len(ops)
    # print(A)
    splits += [(N,)]
    d = len(splits)
    ans = [(q,)] + ops + [(d,)] + splits
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        s = solve()
        if not s: print(-1)
        else:
            for x in s:
                print(*x)
