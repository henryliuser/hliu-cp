// https://cses.fi/problemset/task/1141
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;

    set<int> cur;
    size_t ans = 0;
    vector<int> A(N);
    for (int &x : A) cin >> x;
    for (int i=0, j=0; j < N; ++j) {
        int x = A[j];
        while (cur.count(x))
            cur.erase(A[i++]);
        cur.insert(x);
        ans = max(ans, cur.size());
    }
    cout << ans << '\n';
}
