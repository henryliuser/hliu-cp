#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;

    // find the longest prefix of all positive or all negative
    // compute the minimum ops to make 0 greedily
    // if dx == 0 or dx flips signs, restart on new segment
    ll ans = 0, ch = 0;
    for (int i = 0; i < N; ++i) {
        ll dx = A[i] - B[i];
        if (dx > 0 && ch > 0) {
            if (dx > ch)
                ans += dx-ch;
        }
        else if (dx < 0 && ch < 0) {
            if (dx < ch)
                ans += ch-dx;
        }
        else if (dx < 0 && ch > 0 || dx > 0 && ch < 0)
            ans += abs(dx);
        else ans += abs(dx-ch);
        ch = dx;

    }
    // if (dx == 0)
    //     curr = 0;  // begin new segment
    // else if (curr > 0) {
    //     if (dx > 0 && dx < curr) {
    //         curr = dx;  // achievable with previous operation
    //     }
    //     else if (dx < 0) {
    //         ans -= dx;  // flipped sign, begin new segment
    //         curr = dx;
    //     }
    //     else {
    //         ans += abs(curr-dx);  // curr > dx, use ops to cover
    //         curr = dx; // increase curr
    //     }
    // }
    // else {
    //     if (dx < 0 && dx > curr) {
    //         curr = dx;
    //     }
    //     else if (dx > 0) {
    //         ans += dx;
    //         curr = dx;
    //     }
    //     else {
    //         ans += abs(curr-dx);
    //         curr = dx;
    //     }
    // }
    // }
    cout << ans << '\n';


}
