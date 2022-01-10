// https://codeforces.com/contest/1552/problem/B
// find celebrity leetcode. nice question
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e5+1;

int rnk[MXN][5];

bool superior(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 5; ++k)
        cnt += (rnk[i][k] < rnk[j][k]);
    return cnt >= 3;
}

int solve() {
    memset(rnk, 0, sizeof rnk);
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int& x : rnk[i])
            cin >> x;
    }
    if (N == 1) return 1;
    int cur = 0;
    for (int i = 1; i < N; ++i)
        if (superior(i, cur))
            cur = i;
    for (int i = 0; i < N; ++i) {
        if (i == cur) continue;
        if (superior(i, cur))
            return -1;
    }
    return cur+1;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
