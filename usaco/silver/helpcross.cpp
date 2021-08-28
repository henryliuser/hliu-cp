#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int ans = 0;
    int C, N; cin >> C >> N;
    multiset<int> chickens;
    vector<pair<int, int>> cows(N);
    for (int z = 0; z < C; ++z) {
        int x; cin >> x;
        chickens.insert(x);
    }
    for (int z = 0; z < N; ++z) {
        int end, start; cin >> end >> start;
        cows[z] = {start, end};  // Reversed order, for sort
    }
    sort(cows.begin(), cows.end());
    for (int z = 0; z < N; ++z) {
        auto [end, start] = cows[z];
        auto c = chickens.lower_bound(start);  // find earliest >= start
        if (c == chickens.end()) continue;
        if (*c <= end) {  // if valid, take
            ++ans;
            chickens.erase(c);
        }
    }
    cout << ans << endl;
}
