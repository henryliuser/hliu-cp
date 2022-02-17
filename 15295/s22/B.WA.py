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

from collections import *

if __name__ == '__main__':
    sys.setrecursionlimit(1 << 18)
    N, = intput()
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        u, v = intput()
        adj[u] += [v]
        adj[v] += [u]

    col = [-1] * (N+1)
    def dfs(u, c, p):
        col[u] = c
        for v in adj[u]:
            if v == p: continue
            dfs(v, 1^c, u)
    dfs(1, 0, -1)

    A = [[], []]
    for i in range(1, N+1):
        A[ col[i] ] += [i]

    cnt = {}
    na, nb = map(len, A)
    for x in A[1]: cnt[x] = na
    for u in A[0]:
        for v in adj[u]:
            if v in cnt:
                cnt[v] -= 1
    print( sum(cnt.values()) )
