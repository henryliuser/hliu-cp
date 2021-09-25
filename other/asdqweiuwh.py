L = [1,2,3,4,5]

L[1] # indexing is O(1)
L.find()  # O(N)
L.append(6)  # O(1)
# insert into list is O(N)
L.pop() # deleting from end is O(1)
L.pop(1)  # delete from middle is O(N)

# O(N) - O notation means worst case.
# you can get lucky and return early,
# it's still O(N)
def search(x):
    for i in range(len(L)):
        if L[i] == x:
            return i
    return -1


# "O(2N)" -> O(N)
def foo(N):
    for i in range(N):
        print(i)
    for i in range(N):
        print(i)

d = {}  # empty dict
d = {1:2, 2:76, 3:568, 4:123}                           # dict int:int
d = {"asd":2, "qwyeuyhiu":76, "qwe":568, "qweopi":123}  # dict string:int
s = {1, 2, 3}  # set with 1, 2, 3 in it
s = set()      # empty set

d[key]                 # indexing into dict is O(1)
key in d               # search for exact key match in dict is O(1)
d[new_key] = new_value # adding to dict is O(1)
del d[key]             # removing from dict is O(1)

# Two sum
def twoSum(self, nums, target):
    d = {}
    N = len(nums)
    for i in range(N):
        n = nums[i]
        x = target - n
        if x in d:
            return [i, d[x]]
        d[n] = i

# Two Sum, O(N^2)
for i in range(len(L)):
    for j in range(i+1, len(L)):
        if L[i] + L[j] == target:
            return [i,j]
