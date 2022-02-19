// https://codeforces.com/problemset/problem/1630/B
// crucial reductions:
// +1 if (x <= A[i] <= y) else -1
// any subarray with positive sum is good
// along the prefix sum array, we need increasing subsequence
// which starts at 1 and ends at N
// you can find this path by stitching together the first
// occurrence of each positive int starting from 1
// merge all the final ones together to make K
// a range [x,y] is then valid if pre[N] >= K
// pre[N] just == (# elements in range) - (# elements out of range)
// can compute this with a prefix sum of frequencies, since A[i] <= N
// if this A[i] <= N restriction not present, then you can count it
// with a B = sorted(A) and binary search. or seg tree or whatever u want.
// if some range [x,y] works, (in - out >= K), then there is no need
// to check any range [<=x, >=y], so we run 2 pointers on x and y.
// if A[i] <= N restriction not present, we sort and run 2 pointers on
// all distinct A[i] anyway.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;

void solve() {
    int mx = 0;
    int N, K; scanf("%d%d", &N, &K);
    vector<int> A(N), cnt(N+1);
    for (int &x : A) {
        scanf("%d", &x);
        ++cnt[x];
        mx = max(mx, x);
    }
    for (int i = 1; i <= N; ++i)
        cnt[i] += cnt[i-1];

    int x = 1, y;
    int ans[3] = {inf, inf, inf};
    for (y = 1; y <= mx; ++y) {
        int in = cnt[y] - cnt[x-1];
        while (x <= y && 2*in-N >= K) {
            if (y-x < ans[0])
                ans[0] = y-x,
                ans[1] = x,
                ans[2] = y;
            in = cnt[y] - cnt[++x-1];
        }
    }
    x = ans[1], y = ans[2];
    printf("%d %d\n", x, y);
    if (K == 1) {
        printf("1 %d\n", N);
        return;
    }
    vector<int> iv;
    int cur = 0, target = 1;
    for (int i = 1; i <= N; ++i) {
        int v = A[i-1];
        cur += (x <= v && v <= y) ? 1 : -1;
        if (cur == target) {
            iv.push_back(i);
            if (++target == K) break;
        }
    }
    int p = 1;
    for (int r : iv) {
        printf("%d %d\n", p, r);
        p = r+1;
    }
    if (iv.size() < K)
        printf("%d %d\n", p, N);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}
