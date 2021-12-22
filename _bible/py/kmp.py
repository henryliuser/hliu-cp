# pi[i] = longest prefix of S[0:i+1] that's also a suffix
def kmp(S):
    N = len(S)
    pi = [0] * N
    for i in range(1, N):
        j = pi[i-1]
        while j and S[i] != S[j]:
            j = pi[j-1]
        if S[i] == S[j]:
            j += 1
        pi[i] = j
    return pi
