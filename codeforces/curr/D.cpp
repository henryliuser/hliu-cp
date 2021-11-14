#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N; cin >> N;
    int i, j, k;
    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = ceil((lo+hi)/2.0);
        cout << "? 1 " << mid << endl;
        int x; cin >> x;
        if (x > 0) hi = mid - 1;
        else lo = mid;
    }
    i = lo;
    lo = i+3, hi = N;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        cout << "? " << mid << " " << N << endl;
        int x; cin >> x;
        if (x > 0) lo = mid + 1;
        else hi = mid;
    }
    k = lo;
    lo = i+2, hi = k-1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        int left = (mid-i) * (mid-i-1) / 2;
        int right = (k-mid-2) * (k-mid-1) / 2;
        cout << "? " << i << " " << mid-1 << endl;
        int x; cin >> x;
        if (left < x) {
            hi = mid - 1;
            continue;
        }
        cout << "? " << mid << " " << k << endl;
        int y; cin >> y;
        if (right < y) {
            lo = mid + 1;
            continue;
        }
        if (x==left && y == right) {
            j = mid;
            cout << "! " << i << " " << j << " " << k << endl;
            return;
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
