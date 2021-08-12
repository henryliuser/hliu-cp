from random import randint
# O(calls)
def get_random1(L):
    C = list(L)
    while True:
        size = len(L)
        while size > 0:
            size -= 1
            i = randint(0, size)
            C[i], C[size] = C[size], C[i]
            yield C[size]

# O(2 * calls + 10) lmao
def get_randomN(L):
    while True:
        copy = list(L)
        while L:
            i = randint(0, len(L)-1)
            L[i], L[-1] = L[-1], L[i]
            yield L.pop()

if __name__ == '__main__':
    a = [randint(0,1000) for _ in range(5)]
    g = get_random1(a)
    print(a)
    for _ in range(100):
        print(next(g))
