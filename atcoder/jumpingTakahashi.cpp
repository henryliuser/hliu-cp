// https://atcoder.jp/contests/abc240/tasks/abc240_c
// bitset knapsack
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    bitset<10005> dp = 1;
    int N, X; cin >> N >> X;
    while (N--) {
        int a, b;
        cin >> a >> b;
        dp = (dp << a) | (dp << b);
    }
    cout << (dp[X] ? "Yes" : "No");
}
