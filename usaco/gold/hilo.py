import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    P  = list(intput())

    # for each element x at index i,
    #   find the next lesser element that's
    #   greater than preMin[i+1]
    # preMin[0] = -1
    # then run prefix sum
    # notes:
    # preMin is decreasing, maybe a deque?
    # st is increasing
    mn = -1
    st, nle = [0], [-1] * N
    for i in range(1,N):
        while st[-1] <
        mn = min(mn, P[i])
        st += [P[i]]
