// https://codeforces.com/contest/1612/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solve() {
    int N, a, b;
    cin >> N >> a >> b;
    int M = N / 2;

    set<int> s;
    for (int i = 1; i <= N; ++i)
        s.insert(i);

    vector<int> ans(N);
    ans[0] = a; s.erase(a);
    ans[M] = b; s.erase(b);
    for (int i = 1; i < M; ++i) {
        auto it = prev(s.end());
        ans[i] = *it;
        if (*it < a) return {-1};
        s.erase(it);
    }
    for (int i = 1; i < M; ++i) {
        auto it = s.begin();
        ans[M+i] = *it;
        if (*it > b) return {-1};
        s.erase(it);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        auto s = solve();
        for (int x : s)
            cout << x << " ";
        cout << endl;
    }

}
