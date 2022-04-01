s = input()
A = []
while s[-4:] != "DONE":
    A += [f'"{s}",']
    s = input()
print(*A, sep='\n')
