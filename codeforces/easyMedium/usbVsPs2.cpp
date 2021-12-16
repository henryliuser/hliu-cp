#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<int> usb, ps2;
    while (m--) {
        int x; string t;
        cin >> x >> t;
        if (t == "USB") usb.push_back(-x);
        else ps2.push_back(-x);
    }

    ll ans[2] = {0,0};
    sort(begin(usb), end(usb));
    sort(begin(ps2), end(ps2));
    int k = 2;
    while (k--) {
        for (int i = 0; i < a; ++i) {
            if (usb.empty()) break;
            ++ans[0];
            ans[1] -= usb.back();
            usb.pop_back();
        }
        a = b;
        swap(usb, ps2);
    }
    vector<int> left(usb.size()+ps2.size());
    merge(begin(usb), end(usb), begin(ps2), end(ps2), begin(left));
    for (int i = 0; i < c; ++i) {
        if (left.empty()) break;
        ++ans[0];
        ans[1] -= left.back();
        left.pop_back();
    }
    cout << ans[0] << " " << ans[1] << "\n";

}
