#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string s; cin >> s;
    int N = s.length();
    ll ans = 0, curr = 0, pow = 1;
    vector<int> count(2019);
    count[0] = 1;
    for (int i = N-1; i >= 0; --i) {  // loop backwards so the mod arithmetic
        int digit = s[i] - '0';       // still works out. Add 10^x at each new
        curr = (curr + pow * digit) % 2019;  // point instead of multiplying
        pow = (pow * 10) % 2019;      // a number you've just modded.
        ans += count[curr]++;
    }

    cout << ans << endl;
}
