// https://codeforces.com/contest/1625/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int ans = 0;
    int N, M; cin >> N >> M;
    vector<int> X(N);
    for (int &x : X) cin >> x;
    for (int b = 0; b < 32; ++b) {
        int cnt = 0;
        int bit = (1 << b);
        for (int x : X)
           cnt += !!(x & bit);
        if (cnt > N/2)
            ans |= bit;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
