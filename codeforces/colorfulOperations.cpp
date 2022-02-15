// https://codeforces.com/problemset/problem/1638/E
// range set segment tree to track colors
// on add, 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
string t;
int l, r, c;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    SegTree seg(N);  // track color
    for (int i = 0; i < Q; ++i) {
        cin >> t;
        if (t == "Color") {
            cin >> l >> r >> c;
            seg.upd(l, r, c);
        }
        if (t == "Add") {
            cin >> c >> l;

        }
        if (t == "Query") {

        }
    }



}
