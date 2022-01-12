// https://codeforces.com/contest/1624/problem/E
// common theme: ALL SEGMENTS CAN BE REPRESENTED AS
// CONCATENATIONS OF SEGMENTS OF LENGTH 2 and 3.
// question does not ask for minimum segments, so just
// brute force all segments length 2/3.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using seg = array<int, 3>;

int N, M;
vector<bool> dp;
unordered_map<string, seg> st;

void find(int j, string &s) {
    string t;
    for (int i = 0; i < M-1; ++i) {
        t = s.substr(i, 3);
        st[t] = {i+1, i+3, j};
        t = s.substr(i, 2);     // set this one Afterwards
        st[t] = {i+1, i+2, j};  // to overwrite identical 3's
    }
}

void dfs(int i, string &s, vector<seg> &path) {
    if (i >= M) throw 1;
    if (dp[i]) return;
    string q = s.substr(i, 2);
    if (st.count(q)) {
        path.push_back(st[q]);
        dfs(i+2, s, path);
        path.pop_back();
    }
    q = s.substr(i, 3);
    if (st.count(q)) {
        path.push_back(st[q]);
        dfs(i+3, s, path);
        path.pop_back();
    }
    dp[i] = true;
}

vector<seg> solve() {
    st.clear();
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        find(i+1, s);
    }
    string S; cin >> S;
    vector<seg> path;
    dp.assign(M, false);
    try { dfs(0, S, path); }
    catch (...) {}
    return path;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        auto p = solve();
        if (p.empty()) cout << -1 << '\n';
        else {
            cout << p.size() << '\n';
            for (seg s : p) {
                for (int x : s) cout << x << " ";
                cout << '\n';
            }
        }
    }

}
