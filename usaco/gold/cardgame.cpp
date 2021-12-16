// only slightly tricky realization:
// in an optimal solution, top n/2 used in first half
// bottom n/2 used in second half. otherwise same q as silver
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N; cin >> N;
    vector<int> A(N);
    set<int> ge[2], le[2];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i < N/2) ge[0].insert(A[i]);
        else le[0].insert(A[i]);
    }

    int ans = 0;
    for (int i = 1; i <= 2*N; ++i) {
        if (ge[0].count(i) || le[0].count(i))
            continue;
        if (le[1].size() < N/2) le[1].insert(i);
        else ge[1].insert(i);
    }
    for (int x : ge[0]) {
        auto it = ge[1].lower_bound(x);
        if (it == end(ge[1])) continue;
        ge[1].erase(it);
        ++ans;
    }
    for (int x : le[1]) {
        auto it = le[0].lower_bound(x);
        if (it == end(le[0])) continue;
        le[0].erase(it);
        ++ans;
    }
    cout << ans << "\n";
}
