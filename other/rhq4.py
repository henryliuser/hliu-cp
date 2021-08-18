def f4(a: list, b: list, queries: list) -> list:
    # q[0][i][x] -> b[i] += x
    # q[1][x]    -> count i,j such that a[i] + b[j] == x
    ans = []  # results of q[1]
    M, N, Q = len(a), len(b), len(queries)
    count_b = defaultdict(int)
    for v in b: count_b[v] += 1

    def q0(q):  # process query type 0
        t, i, x = q
        count_b[b[i]] -= 1
        b[i] += x
        count_b[b[i]] += 1

    def q1(q):  # process query type 1
        t, x = q
        res = sum(count_b[x-v] for v in a)
        ans.append(res)

    for q in Q:
        if q[0] == 0: q0(q)
        if q[0] == 1: q1(q)

    return ans
