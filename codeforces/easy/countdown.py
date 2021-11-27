T = int(input())

def solve():
    N = int(input())
    A = list(map(int, input()))
    return sum(A) + sum(1 for i,a in enumerate(A) if a!=0 and i!=N-1)

if __name__ == '__main__':
    for _ in range(T):
        print( solve() )
