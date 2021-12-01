#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    s.push_back('?');

    ll ans = 0, sz = 1;
    for (int i = 1; i <= N; ++i) {
        if (s[i] != s[i-1]) {
            ans += sz * (sz-1) / 2ll;
            sz = 0;
        }
        ++sz;
    }

    cout << ans << "\n";

}
