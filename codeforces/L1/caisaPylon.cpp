#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int t; cin >> t;
        ans = max(ans, t);
    }
    cout << ans << endl;

}
// 340 49 9 1 -15
// -15 -30 -45 100
// 7 5 83 92 3 3 3 340 49 9 1 -15
