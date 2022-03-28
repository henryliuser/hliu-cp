#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

string solve() {
    ll S = 0;
    int N; cin >> N;
    map<ll, int> cnt;
    vector<ll> A(N);
    for (ll &x : A) {
        cin >> x;
        ++cnt[x];
        S += x;
    }
    vector<ll> left(1,S);
    while (!left.empty()) {
        ll x = left.back();
        left.pop_back();
        if (cnt.count(x)) {
            if (--cnt[x] <= 0)
                cnt.erase(x);
            continue;
        }
        if (x == 1) break;
        if (cnt.empty()) break;
        if (x < begin(cnt)->first) break;
        ll a = x/2;
        ll b = x-a;
        left.push_back(a);
        left.push_back(b);
    }
    return cnt.empty() ? "YES" : "NO";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
