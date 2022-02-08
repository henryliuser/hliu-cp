// https://codeforces.com/contest/1486/problem/D
// median binary search trick + prefix sum, suffix max
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
vector<int> A;

int f(int i, int g) { return (A[i] >= g) ? 1 : -1; }

bool check(int g) {
    vector<int> psum(N+1);
    for (int i = 0; i < N; ++i)
        psum[i+1] = psum[i] + f(i,g);
    vector<int> smax = psum;
    for (int i = N-1; i >= 0; --i)
        smax[i] = max(smax[i], smax[i+1]);

    int res = INT_MIN;
    for (int i = 0; i < N-K+1; ++i) {
        int q = smax[i+K];
        res = max(res, q-psum[i]);
    }
    return res > 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    A.resize(N);
    for (int &x : A) cin >> x;

    int lo = 0, hi = N+1;
    while (lo < hi) {
        int mid = lo + (hi-lo+1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}
