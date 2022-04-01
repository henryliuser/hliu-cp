// https://codeforces.com/contest/1660/problem/C
// just an interval scheduling problem
// crucial reduction is the following:
// start by deleting everything.
// look for adjacent pairs to preserve
// each pair you preserve means u get to delete 2 fewer
// u can't preserve overlapping pairs
// problem is reduced to: N - 2*(max # of disjoint intervals)
// can solve with greedy
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

ll solve() {
    string S; cin >> S;
    int N = S.size();
    map<int, int> mp;
    vector<pair<int,int>> V;
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        if (mp.count(c))
            V.push_back({mp[c], i});
        mp[c] = i;
    }
    if (V.size() == 0) return N;

    int del = N-2;
    int last = V[0].second;
    for (int i = 1; i < V.size(); ++i) {
        auto &iv = V[i];
        int l = iv.first;
        int r = iv.second;
        if (l > last) {
            del -= 2;
            last = r;
        }
    }
    return del;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
