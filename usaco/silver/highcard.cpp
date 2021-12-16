#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> E(N);
    unordered_set<int> s;
    for (int i = 0; i < N; ++i) {
        cin >> E[i];
        s.insert(E[i]);
    }
    set<int> B;
    for (int i = 1; i <= 2*N; ++i) {
        if (s.count(i)) continue;
        B.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int e = E[i];
        auto it = B.upper_bound(e);
        if (it == end(B)) continue;
        B.erase(it);
        ++ans;
    }
    cout << ans << "\n";
}
