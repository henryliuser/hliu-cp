#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int a, b; cin >> a >> b;
    if (a == 0) return 0;
    if (b == 0) return 0;
    if (a+b < 4) return 0;
    if (a > b) swap(a, b);
    if (a == b) return a/2;
    int gap = b-a;
    int q = min(a, gap / 2);
    a -= q; b -= q*3;
    return q+min(a,b)/2;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";

}
