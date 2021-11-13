#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> pre(N+1);
    for (int i = 0; i < N; ++i) {
        cin >> pre[i+1];
        pre[i+1] += pre[i];
    }
    while (Q--) {
        int L, R; cin >> L >> R;
        cout << pre[R] - pre[L-1] << "\n";
    }
}
