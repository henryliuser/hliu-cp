input()
L = sorted(input())
le = len(L)
left, right = 0, le
for x in range(le):
    left += int(L[x] == '0' or L[x] == '1')
# for x in range(le-1, -1, -1):
#     right -= int(L[x] == '0' or L[x] == '1')
print("".join(L[left:]))
