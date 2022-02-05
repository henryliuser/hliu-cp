
def ok(x):
    s = hex(x)[2:]
    for i in range(len(s)-1, 0, -2):
        if int(s[i-1] + s[i+1]) == 0:
            return False
    if len(s) % 2: return s[0] != 0
    return True

ans = []
for a in range(2**31-1):
    if not ok(a): continue
    for b in range(2**31-1):
        if not ok(b): continue
        if a * b > 2**31-1:
            ans += [(hex(a),hex(b))]

for a in ans:
    print(a)
