#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
string solve() {
    string s; cin >> s;
    sort(all(s));
    return s;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
