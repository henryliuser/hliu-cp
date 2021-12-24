from time import time
x = 600851475143

def pf(x):
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            return pf(x//i) | {i}
    return {x}

start = time()
print(max(pf(x)))
end = time()
print(end-start)
