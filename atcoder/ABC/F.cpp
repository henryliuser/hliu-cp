// https://atcoder.jp/contests/abc229/tasks/abc229_f
// nice question.
// let A = [indices of Y's]
// let B[i] = A[i] - i for i in A  (adjacency trick)
// let D[i] = sum of distances from 0 to i in B
// binary search on the window size (answer)
// run sliding window median on the sorted array B
// use D to compute sums and calculate predicate result

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll K, M;
string S;
vector<ll> A, B;

struct DistSum {
    vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
    DistSum(vector<ll> &a) {
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = (a[i] - a[i-1]) + d[0][i-1];
            d[1][n-i-1] = (a[n-i] - a[n-i-1]) + d[1][n-i];
            p[0][i] = d[0][i] + p[0][i-1];
            p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
        }
    }
    ll query(int src, int i) {
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll ogd = d[q][src];
        ll len = abs(src-i);
        return diff - ogd * len;
    }
};

bool check(ll g, DistSum &ds) {
    for (int i = 0; i < M-g+1; ++i) {
        ll mid   = i + g/2;
        ll left  = ds.query(mid, i);
        ll right = ds.query(mid, i+g-1);
        if (left + right <= K) return true;
    }
    return false;
}

int solve() {
    cin >> S >> K;
    int N = S.size();
    for (int i = 0; i < N; ++i)
        if (S[i] == 'Y')
            A.push_back(i);
    M = A.size();
    B.resize(M);
    for (int i = 0; i < M; ++i)
        B[i] = A[i] - i;

    DistSum ds(B);
    if (M <= 1) return M;
    int lo = 2, hi = M;
    while (lo < hi) {
        int mid = lo + ceil((hi-lo) / 2.0);
        if (check(mid, ds)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";
}
