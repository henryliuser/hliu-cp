# ........
# https://codeforces.com/contest/1638/problem/D
# .....
# tle without fastio.
# ....
# .........
# rage
from collections import deque

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

def ok(i, j):
    a, b = A[i][j:j+2]
    c, d = A[i+1][j:j+2]
    x = {a,b,c,d}
    if len(x) == 1 and 0 in x: return 0
    if len(x) == 1: return x.pop()
    if len(x) == 2 and 0 in x:
        x.remove(0)
        return x.pop()
    return 0

def check(r, c):
    for i in range(r-1, r+2):
        for j in range(c-1, c+2):
            if i < 0 or i >= N-1: continue
            if j < 0 or j >= M-1: continue
            if seen[i][j]: continue
            col = ok(i,j)
            if col != 0:
                seen[i][j] = 1
                q.append( (i,j,col) )

if __name__ == '__main__':
    N, M = intput()
    A = [list(intput()) for _ in range(N)]
    seen = [[0]*(M-1) for _ in range(N-1)]

    q = deque([])
    for r in range(N-1):
        for c in range(M-1):
            col = ok(r,c)
            if col != 0:
                q.append( (r,c,col) )
                seen[r][c] = 1

    ans = []
    while q:
        r,c,col = q.popleft()
        ans += [ f"{r+1} {c+1} {col}" ]
        A[r][c:c+2]   = [0, 0]
        A[r+1][c:c+2] = [0, 0]
        check(r,c)

    for row in A:
        if any(x != 0 for x in row):
            print(-1); exit()

    print(len(ans))
    print( '\n'.join(reversed(ans)) )
