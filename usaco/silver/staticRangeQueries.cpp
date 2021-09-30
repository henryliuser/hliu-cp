#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;

int main() {
    set<int> points;
    int N, Q; cin >> N >> Q;
    vector<tup> arr(N);
    vector<int> pre(2*N+2);
    int l, r, v;
    for (int i = 0; i < N; ++i) {
        cin >> l >> r >> v;
        arr[i] = {l, r, v};
        points.insert(l);
        points.insert(r);
    }
    for (int i = 0; i < N; ++i) {
        tie(l, r, v) = arr[i];
        int x = distance(points.begin(), points.find(l));
        int y = distance(points.begin(), points.find(r));
        pre[x+1] += v;
        pre[y+2] -= v;
    }
    for (auto pm : pre) cout << pm << " "; cout << endl;
    for (int i = 1; i < 2*N+2; ++i)
        pre[i] += pre[i-1];

    for (auto pm : pre) cout << pm << " "; cout << endl;
    for (int i = 0; i < Q; ++i) {
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << endl;
    }

}
