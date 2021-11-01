import io, os, sys
read = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input = lambda : read().decode()
print = lambda x : sys.stdout.write(f"{x}\n")
intput = lambda : map(int, input().split())

# x = read().decode()
# print(x)
# x,y = intput()
# x = 123
# print(x)
# x = input()
# print(pow(2,7))
