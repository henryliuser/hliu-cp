A = [1,2,3,4,5]
def asd(a, b, c):
    # calculate something, return a value
    # achieve some side effect
    print(A)
    A[0] = 90  # change that is observed outside of the function context
    return a + b + c

# print( asd(1,2,3) )  # print(6)
# print(A)  # [90,2,3,4,5]
#
# d = {}  # empty dict
# d1 = {1:2, 3:4, 5:6}  # 1->2   3->4
# s = set()  # empty set
# s1 = {1, 2, 3}
# s1.add(1)

# for loops in python
# range(N) # <- (0,1,2,3,4, ... N-1)
# for i in range(N):  # <-
#     print(i)
#
# L = [2,7,9,2]
# for x in L:
#     print(x)


# Time Complexity
# O(1) - constant time
# O(log N) - logarithmic
# O(N) - linear time
# O(N log N)
# O(N^2) - quadratic time

asd = [1,2,3,4,5]
def listSum1(L):  # O(N)
    s = 0
    for x in L:
        s += x
    return s

def listSum2(L):  # O(N)
    s = 0
    for x in L:
        s += x
    for x in L:
        s += x
    return s

def someFunc(L):  # O(1)
    return L[0] + 5

# print all unique pairs of elements
# [1,2,3,4,5]
# [1,2], [1,3], [1,4], [1,5]
# [2,3], [2,4], [2,5]
# [3,4], [3,5]
# [4,5]
# L = [1,2,3]

# range(n) = (0,1,2,3 ... n-1)
# range(i, n) = (i, i+1, i+2, ... , n-1)

# Time: O(N^2)
def printPairs(L):
    N = len(L)
    for i in range(N):  # iterate over Firsts
        x = L[i]
        for j in range(i+1, N):
            y = L[j]
            print(x, y)

# printPairs([1,2,3,4,5])

# Time: O(N^3 + M)
def badComputation(L, R):
    N = len(L)
    M = len(R)
    s = 0
    for x in L:
        for y in L:
            for z in L:
                s += x*y*z
    for q in R:
        s += q
    return s

L = [0, 5, 34, 3, 2, 78]
# L[2]  <-- O(1)
# Time: O(N)
def find(L, x):  # return True if x is inside L, somewhere, else False
    for y in L:
        if x == y:
            return True
    return False

# D = {1:2, 7:3, 3:8, -4:9}  # HashMap
# D = {"strqwe":-4, (2,3):123}
# D[1] <- 2  O(1)          # D[i] -> L[ hash(i) ]
# (x in D) <- O(1)
# S =  set()
# S = {1, 6, 9, 7, 23}
# (x in S)  # O(1)

# O(N^2)
def hasDuplicate1(L):  # return True if there's a duplicate in L, else False
    N = len(L)
    for i in range(N):
        for j in range(i+1, N):
            if L[i] == L[j]: return True
    return False

# O(N)
def hasDuplicate2(L):
    N = len(L)
    seen = set()
    for x in L: # O(N)
        if x in seen: return True # O(1)
        seen.add(x)  # O(1)
    return False

def hasDuplicate3(L):
    return len(set(L)) != len(L)

# hasDuplicate4([1,2,3,4,1]) -> (0,4)
def hasDuplicate4(L):  # return indices of duplicates, else (-1, -1)
    N = len(L)
    seen = {}
    for i in range(N):
        x = L[i]
        if x in seen:
            return (seen[x], i)
        seen[x] = i
    return (-1, -1)


# O(N^2) 2sum -- loop over all unique pairs
def twoSum1(nums, target):
    for i in range(N):
        for j in range(i+1, N):
            if nums[i] + nums[j] == target:
                return (i,j)

# O(N) 2sum -- hash on stuff we've already seen
def twoSum2(nums, target):
    N = len(nums)
    seen = {}
    for i in range(N):
        x = nums[i]
        t = target - x
        if t in seen:
            return (seen[t], i)
        seen[x] = i
