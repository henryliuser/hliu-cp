#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h; cin >> n >> h;
    int ans = 0;
    while (n--) {
        int a; cin >> a;
        ans += 1 + (a > h);
    }
    cout << ans << endl;
}
