#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;

ll solve(char ch) {
    int res = 0, curr = 0;
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(0);
    for (int i = 1; i <= N; ++i) {
        curr += (S[i-1]==ch) ? 1 : -1;
        auto &v = mp[curr-i+2];
        auto it = upper_bound(begin(v), end(v), i-3);
        res += it - begin(v);
        mp[curr-i].push_back(i);
    }
    return res;
}

int main() {
    cin >> N >> S;
    cout << solve('H') + solve('G') << "\n";
}

// 012345
//  HHGHH
// 012123
// HHG pre[r] - pre[l] = r-l-1
// pre[r] - r = pre[l] - l + 1
