#include <bits/stdc++.h>
using namespace std;

int solve() {
    int k; cin >> k;
    return 100/gcd(k, 100);
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << endl;
}
