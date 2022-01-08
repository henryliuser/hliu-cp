// https://codeforces.com/contest/1617/problem/C
// notice that the range of possible values of x % y is
// all 0 <= i < (x-1)//2
// greedily take good values at the beginning, then binary search
// to find the minimum of the remaining
// technically don't need binary search either. just take min
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll ans = 0;
    int N; cin >> N;
    map<int, int> cnt;
    set<int> s;
    for (int i = 1; i <= N; ++i)
        s.insert(i);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (s.count(x)) s.erase(x);
        else ++cnt[x];
    }
    for (int i : s) {
        auto it = cnt.lower_bound(i*2+1);
        if (it == end(cnt)) return -1;
        int x = it->first;
        if (--cnt[x] <= 0)
            cnt.erase(x);
        ++ans;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
