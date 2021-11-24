// https://codeforces.com/problemset/problem/1610/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> A, B;

bool check(int g) {
    int ans = 0;
    int reqA = g-1, reqB = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= reqA && B[i] >= reqB) {
            ++ans; --reqA; ++reqB;
        }
    }
    return ans >= g;
}

int solve() {
    cin >> N;
    A.resize(N); B.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];

    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = lo + ceil((hi-lo)/2.0);
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
