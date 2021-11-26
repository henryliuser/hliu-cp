#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> dp;

    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        auto it = upper_bound(begin(dp), end(dp), x);
        if (it == end(dp)) dp.push_back(x);
        else *it = x;
    }
    cout << dp.size() << "\n";

}
