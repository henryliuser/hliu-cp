#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    map<int, int> ans;
    for (int i = 0; i < N; ++i) {
        int d, s; cin >> d >> s;
        if (d != 1) continue;
        if (ans.count(s) && ans[s] == i) continue;
        ans[i] = s;
    }
    cout << ans.size() << '\n';
    for (auto &p : ans)
        cout << p.first << " " << p.second << '\n';
}
