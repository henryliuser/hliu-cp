#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

void solve() {
    int n; cin >> n;
    multiset<pii> nums;
    vector<string> meets;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x == 0) continue;
        nums.insert({x, i});
    }
    while (1) {
        if (nums.empty()) break;
        auto hi = prev(nums.end());
        auto lo = nums.begin();
        if (lo == hi) break;
        pii top = *hi;
        pii bot = *lo;
        nums.erase(hi);
        nums.erase(lo);
        int nextHi = -1;
        if (!nums.empty())
            nextHi = (*nums.rbegin()).f;
        while (bot.f > 0 && top.f >= nextHi) {
            string m = to_string(bot.s) + " " + to_string(top.s);
            meets.push_back(m);
            --bot.f, --top.f;
        }
        if (bot.f > 0) nums.insert( {bot.f, bot.s} );
        if (top.f > 0) nums.insert( {top.f, top.s} );
    }
    cout << meets.size() << endl;
    for (string& s : meets)
        cout << s << endl;

}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
