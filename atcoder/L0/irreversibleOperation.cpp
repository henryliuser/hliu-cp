// https://atcoder.jp/contests/agc029/tasks/agc029_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    int N = s.size();
    vector<ll> sfx(N);
    sfx[N-1] = (s[N-1] == 'W') ? 1 : 0;
    for (int i = N-2; i+1; --i) {
        int x = (s[i] == 'W') ? 1 : 0;1
        sfx[i] = sfx[i+1] + x;
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'B')
            ans += sfx[i];
    }
    cout << ans << "\n";

}
