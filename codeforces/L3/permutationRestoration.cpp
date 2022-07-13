// https://codeforces.com/contest/1701/problem/D
// PQ and do interval scheduling ish thing
#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
#define all(x) begin(x), end(x)

template <class P>
int bisect(int l, int r, P pred) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (pred(m)) r = m;
        else l = m+1;
    }
    return l;
}

auto lower = [](int i, int b) { return [=](int g) mutable { return i/g <= b; }; };
auto upper = [](int i, int b) { return [=](int g) mutable { return i/g  < b; }; };

void solve() {
    int N; cin >> N;
    vector<int> B(N);
    for (int &x : B) cin >> x;

    vector<vector<pi>> axis(N+5);
    for (int i = 0; i < N; ++i) {
        int lb = bisect( 1, N,   lower(i+1, B[i]) );
        int ub = bisect( 1, N+1, upper(i+1, B[i]) ) - 1;

        axis[lb].emplace_back(-ub, i);
    }

    vector<int> ans(N);
    priority_queue<pi> pq;
    for (int x = 1; x <= N; ++x) {
        for (auto p : axis[x])
            pq.push(p);

        auto [y,i] = pq.top();
        ans[i] = x;
        pq.pop();
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
