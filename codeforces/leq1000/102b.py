# B. Sum of Digit
st = input()
ss = 0
c = 0
while len(st) > 1:
    ss = sum(map(int, st))
    st = str(ss)
    c += 1
print(c)
