# https://projecteuler.net/problem=1
# If we list all the natural numbers below 10 that are multiples of 3 or 5,
# we get 3, 5, 6 and 9. The sum of these multiples is 23.

# Find the sum of all the multiples of 3 or 5 below 1000.

# O(1) math
N = 1000 - 1
sumUp = lambda x: (x * (x+1)) // 2
ans = 3*sumUp(N//3) + 5*sumUp(N//5) - 15*sumUp(N//15)
print(ans)

# no division/mod, still looping
N = 1000
s1 = sum(range(3,N,3))
s2 = sum(range(5,N,5))
s3 = sum(range(15,N,15))
print(s1 + s2 - s3)

# trivial, lots of modulo
print(sum(x for x in range(1,1000) if not ((x%3) and (x%5))))
