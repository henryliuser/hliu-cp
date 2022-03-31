#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    string S = "<3";
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        S.append(s);
        S.append("<3");
    }
    N = S.size();

    int i = 0;
    string T; cin >> T;
    for (char c : T)
        if (c == S[i])
            if (++i >= N)
                break;

    cout << (i==N ? "yes" : "no") << '\n';
}
