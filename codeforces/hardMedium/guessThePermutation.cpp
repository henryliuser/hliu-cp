// https://codeforces.com/contest/1589/problem/D
// WA rn
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int a, int b) {
    printf("? %d %d\n");
    fflush(stdout);
    int x; cin >> x;
    return x;
}

void solve() {
    int N; cin >> N;
    int i, j, k;
    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = ceil((lo+hi)/2.0);
        int x = ask(1, mid);
        if (x > 0) hi = mid - 1;
        else lo = mid;
    }
    i = lo;
    lo = i+3, hi = N;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        int x = ask(mid, N);
        if (x > 0) lo = mid + 1;
        else hi = mid;
    }
    k = lo;
    lo = i+2, hi = k-1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        int left = (mid-i) * (mid-i-1) / 2;
        int right = (k-mid-2) * (k-mid-1) / 2;
        int x = ask(i, mid-1);
        if (left < x) {
            hi = mid - 1;
            continue;
        }
        int y = ask(mid, k);
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
