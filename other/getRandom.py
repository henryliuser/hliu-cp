L = [1,3,5,6,7,82,43,3]

def get_random(C):
    N = len(C)
    while True:
        s = set(set(range(N)))
        while s:
            idx = s.pop()
            print(f"idx: {idx}")
            yield C[idx]

gen = get_random(L)
for _ in range(10000):
    print(next(gen))


# doesn't work lmfao
