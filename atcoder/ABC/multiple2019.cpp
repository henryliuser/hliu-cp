#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string s; cin >> s;
    int N = s.length();
    ll ans = 0, curr = 0, pow = 1;
    vector<int> count(2019);
    count[0] = 1;
    for (int i = N-1; i >= 0; --i) {
        int digit = s[i] - '0';
        curr = (curr + pow * digit) % 2019;
        pow = (pow * 10) % 2019;
        ans += count[curr]++;
    }

    cout << ans << endl;
}
