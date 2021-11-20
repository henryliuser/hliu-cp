#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int x; cin >> x;
    int sum = 0;
    set<int> s;
    for (int i = 1; i*i < x; ++i) {
        if (x % i) continue;
        if (!s.count(i)) {
            s.insert(i);
            sum += i;
            if (sum > x) return "abundant";
        }
        int c = x/i;
        if (c == x) continue;
        if (!s.count(c)) {
            s.insert(c);
            sum += c;
            if (sum > x) return "abundant";
        }
    }
    return (sum == x) ? "perfect" : "deficient";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
