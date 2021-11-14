// ... idk
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solve() {
    int N; cin >> N;
    string S; cin >> S;
    int i = 0, j = N-1;
    vector<int> v;
    while (i < N && S[i] == '0') ++i;
    while (j + 1 && S[j] == '1') --j;
    while (i < j) {
        v.push_back(1 + i++);
        v.push_back(1 + j--);
        while (i < N && S[i] == '0') ++i;
        while (j + 1 && S[j] == '1') --j;
    }
    sort(rbegin(v), rend(v));
    return v;
}

int main() {
    int T; cin >> T;
    while (T--) {
        auto ans = solve();
        int k = ans.size();
        cout << (k>0) << "\n";
        if (!k) continue;
        cout << k << " ";
        while (k--) cout << ans[k] << " ";
        cout << "\n";
    }
}
