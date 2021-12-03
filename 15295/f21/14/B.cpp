#include <bits/stdc++.h>
using namespace std;
using pt = array<int, 2>;
using ll = long long;

ll dist(int x1, int y1, int x2, int y2) {
    ll dx = abs(x2 - x1);
    ll dy = abs(y2 - y1);
    return dx * dx + dy * dy;
}

struct Circle {
    int rx, ry;
    ll rad = 0;
    int cnt = 0;
    map<ll, int> dists;
    void add(int x, int y) {
        ++cnt;
        ll d = dist(x, y, rx, ry);
        ++dists[d];
        rad = max(rad, d);
    }
    void pop(int x, int y) {
        ll d = dist(x, y, rx, ry);
        if (--dists[d] <= 0)
            dists.erase(d);
        if (--cnt)
            rad = dists.rbegin()->first;
    }
};

int main() {
    Circle c[2];
    cin >> c[0].rx >> c[0].ry;
    cin >> c[1].rx >> c[1].ry;
    int N; cin >> N;
    vector<pt> A(N);
    for (pt &p : A)
        cin >> p[0] >> p[1];

    sort(begin(A), end(A));

    for (pt &p : A) c[1].add(p[0], p[1]);
    ll ans = c[1].rad;
    for (pt &p : A) {
        int x = p[0], y = p[1];
        c[0].add(x, y);
        c[1].pop(x, y);
        ans = min(ans, c[0].rad + c[1].rad);
    }
    for (int i = N-1; i >= 0; --i) {
        int x = A[i][0], y = A[i][1];
        c[1].add(x, y);
        c[0].pop(x, y);
        ans = min(ans, c[0].rad + c[1].rad);
    }

    sort(begin(A), end(A), [](pt &a, pt &b) {  // by y-coord
        return a[1] < b[1];
    });
    for (pt &p : A) {
        int x = p[0], y = p[1];
        c[0].add(x, y);
        c[1].pop(x, y);
        ans = min(ans, c[0].rad + c[1].rad);
    }
    for (int i = N-1; i >= 0; --i) {
        int x = A[i][0], y = A[i][1];
        c[1].add(x, y);
        c[0].pop(x, y);
        ans = min(ans, c[0].rad + c[1].rad);
    }

    cout << ans << "\n";

}
