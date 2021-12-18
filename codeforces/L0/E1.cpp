#include <bits/stdc++.h>
using namespace std;

void solve() {
    deque<int> d;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        if (d.empty() || x <= d.front()) d.push_front(x);
        else d.push_back(x);
    }
    int c = 0;
    for (int x : d) {
        if (c++ == d.size()-1) cout << x;
        else cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
