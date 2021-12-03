import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    if N < 10: s = f"00{N}"
    elif N < 42: s = f"0{N}"
    else: s = f"0{N+1}"
    print("AGC",s,sep='')
