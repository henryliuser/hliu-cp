# O(calls)
def get_random(L):
    while True:
        size = len(L)
        while size > 0:
            size -= 1
            i = randint(0, size)
            L[i], L[size] = L[size], L[i]
            yield L[size]

# O(2 * calls + 10) lmao
def get_random(L):
    while True:
        copy = list(L)
        while L:
            i = randint(0, len(L)-1)
            L[i], L[-1] = L[-1], L[i]
            yield L.pop()
