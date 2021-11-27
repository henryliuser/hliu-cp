// good (harsh) intro to casework, i guess.
#include <bits/stdc++.h>
using namespace std;

bool find(string a, string &b) {
    return b.find(a) != string::npos;
}

int solve() {
    int N; cin >> N;
    string S; cin >> S;
    int ans = INT_MAX;
    if (find("aa", S)) return 2;
    if (find("aba", S) || find("aca", S)) return 3;
    if (find("abca", S) || find("acba", S)) return 4;
    if (find("abbacca", S) || find("accabba", S)) return 7;
    return -1;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
}
