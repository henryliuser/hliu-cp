#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> A;
int mex() {
    for(int i = 0; i < n; ++ i)
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);

    for(int i = 0; i < n; ++ i)
        if(A[i] != i + 1)
            return i + 1;

    return n + 1;
}

void solve() {
    cin >> n; A.resize(n);
    for (int &x : A) cin >> x;
    vector<int> B = A;
    sort(begin(B), end(B));
    map<int, int> cnt;
    for (int x : A) ++cnt[x];
    vector<int> Q;
    for (auto p : cnt) {
        if (--p.second <= 0)
            Q.push_back(p.first);
    }
    for (int x : Q) cnt.erase(x);

    int q = mex();
    for (int i = 0; i < q; ++i) {
        auto u = upper_bound(begin(B), end(B), i);
        auto l = lower_bound(begin(B), end(B), i);
        cout << u-l << " ";
    }
    cout << "0 ";
    ll last = 0;
    for (int i = q+1; i <= n; ++i) {
        if (cnt.empty()) {
            cout << -1 << " ";
            continue;
        }
        auto it = cnt.lower_bound(i-1);
        if (it == begin(cnt)) {
            cout << -1 << " ";
            continue;
        }
        auto p = *(--it);
        cnt.erase(it);
        ll y = (i-1) - (p.first);
        if (--p.second)
            cnt[p.first] = p.second;
        cout << last + y << " ";
        last += y;
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
