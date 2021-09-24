#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll curr; cin >> curr;
    ll ans = curr;
    while (--N) {
        ll x; cin >> x;
        curr = max(curr + x, x);
        ans = max(ans, curr);
    }
    cout << ans << endl;

}
