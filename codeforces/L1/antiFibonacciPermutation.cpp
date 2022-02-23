// https://codeforces.com/contest/1644/problem/B
// greedy and swap at the end
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    set<int> s;
    int N; cin >> N;
    for (int i = 1; i <= N; ++i)
        s.insert(i);

    for (int i = 1; i <= N; ++i) {
        set<int> cur = s;
        cur.erase(i);
        vector<int> res(1, i);
        auto it = cur.begin();
        res.push_back(*it);
        cur.erase(it);
        for (int j = 3; j <= N; ++j) {
            int q = res.size();
            int r = res[q-1] + res[q-2];
            it = begin(cur);
            if (*it == r) it = prev(end(cur));
            res.push_back(*it);
            cur.erase(it);
        }
        if (res[N-1] == res[N-2] + res[N-3])
            swap(res[N-1], res[N-2]);

        for (int j = 0; j < N; ++j)
            cout << res[j] << " ";
        cout << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
