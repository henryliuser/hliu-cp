#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> P(N), pre(N+1);
    for (int &x : P) cin >> x;
    for (int i = 1; i < N; ++i) {
        if (P[i] > P[i-1]) continue;
        ++pre[ P[i] ], --pre[ P[i-1] ];
    }
    int ans = 0;
    for (int x = 0; x <= N; ++x) {
        ans += pre[x];
        cout << ans << "\n";
    }
}
