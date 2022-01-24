// https://codeforces.com/problemset/problem/1628/B
// max length necessary for an awesome seq is 2
// casework lmao
// a
// a ba
// ab ba
// ab cba
// abc ba
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int N; cin >> N;
    vector<string> A(N);
    for (auto &s : A) cin >> s;

    for (int i : {0,1}) {
        set<string> seen;
        for (auto &s : A) {
            string t = s;
            reverse(begin(t), end(t));
            if (s == t) return "YES";  // singular palindrome
            if (seen.count(t)) return "YES";  // seen reverse
            int M = s.size();
            if (M == 3) {
                string v = t.substr(0, 2);
                if (seen.count(v)) return "YES";  // ab cba
                string q = t.substr(0, 1);
                if (t[1] == t[2] && seen.count(q)) return "YES";  // a cca
            }
            if (M == 2) {
                string q = t.substr(0, 1);
                if (seen.count(q)) return "YES";  // a ba
            }
            seen.insert(s);
        }
        reverse(begin(A), end(A));
        for (auto &s : A)
            reverse(begin(s), end(s));
    }
    return "NO";

}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
