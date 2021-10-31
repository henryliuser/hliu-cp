s = ""

while 3:
    s = input().split()
    try:
        int(s[0])
        s = s[1:]
    except: pass
    print(' '.join(s))
