import random, time

arr = []
for x in range(1000000):
    arr.append(random.randint(0, 100000))

def linearSearch(arr:[], x) -> bool:
    # O(N) time
    for z in range(len(arr)):
        if arr[z] == x:
            return True
    return False

def binarySearch(arr, x) -> bool:
    # O(log N) time
    # return true or false
    lo = 0
    hi = len(arr) - 1
    while lo < hi:
        mid = (lo+hi) // 2
        if arr[mid] == x: return True
        elif arr[mid] < x: lo = mid + 1
        else: hi = mid -1
    return False

if __name__ == "__main__":
    print("Testing linear search: ")
    start = time.time()
    for x in range(1000):
        r = random.randint(0, 100000)
        linearSearch(arr, r)
    end = time.time()
    print(end - start)
    print("\nTesting binary search: ")
    start = time.time()
    arr.sort()
    for x in range(1000):
        r = random.randint(0, 100000)
        binarySearch(arr, r)
    end = time.time()
    print(end - start)
