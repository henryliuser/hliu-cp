// pretty instructive i guess.
// sort by exactly the thing you want.
#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string &b) {
    string c = a+b;
    string d = b+a;
    return c < d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string ans;
    int N; cin >> N;
    vector<string> A(N);
    for (auto &s : A) cin >> s;
    sort(begin(A), end(A), cmp);
    for (auto &s : A) ans.append(s);

    cout << ans << "\n";
}
