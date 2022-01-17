import sys, random
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    rank = [list(intput()) for _ in range(N)]

    def beats(i, j, res=0):  # i beats itself
        for k in range(5):
            res += (rank[i][k] <= rank[j][k])
        return res >= 3

    ord = list(range(N))
    random.shuffle(ord)
    for i in range(N):
        if all( beats(i, ord[j]) for j in range(N) ):
            return i+1
    return -1

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
