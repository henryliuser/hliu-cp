#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int n, m; cin >> n >> m;
    if (n == 1 && m == 1) return 0;
    if (min(n,m) == 1) return 1;
    return 2;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
