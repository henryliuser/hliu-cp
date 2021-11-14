import random, time

def linearSearch(arr:[], x) -> bool:
    # O(N) time
    for z in range(len(arr)):
        if arr[z] == x:
            return z
    return -1

def binarySearch(arr, x) -> bool:
    # O(log N) time
    # return true or false
    lo = 0
    hi = len(arr) - 1
    while lo < hi:
        mid = (lo+hi) // 2
        val, idx = arr[mid]
        if val == x: return idx
        elif val < x: lo = mid + 1
        else: hi = mid -1
    return -1

if __name__ == "__main__":
    arr = []
    for x in range(1000000):
        arr.append(random.randint(0, 100000))
    searches = [random.randint(0, 100000) for _ in range(10)]
    print(searches)

    print("Testing linear search: ")
    cnt, found1 = 0, []
    start = time.time()
    for s in searches:
        i = linearSearch(arr, s)
        if i != -1: found1.append(i)
    end = time.time()
    print("Time:", end - start)
    print(cnt, sorted(found1))

    print("\nTesting binary search: ")
    cnt, found2 = 0, []
    start = time.time()
    arr = sorted( ((x,i) for i,x in enumerate(arr)) )
    mid = time.time()
    for s in searches:
        i = binarySearch(arr, s)
        if i != -1: found2.append(i)
    end = time.time()
    print("Sort Time:   ", mid - start)
    print("Search Time: ", end - mid)
    print("Total Time:  ", end - start)
    print(cnt, sorted(found2))
