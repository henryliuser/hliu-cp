// https://codeforces.com/contest/1625/problem/B
// binary search, check with prefix sum offline range query
// build intervals of occurrences and check if any overlap
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> A(N);

bool check(int sz) {
    if (!sz) return false;
    vector<vector<int>> add(sz+1);
    vector<vector<int>> del(sz+1);
    for (int i = 0; i < N; ++i) {
        int L = 0, R = sz-1;
        if (i < sz-1) R = min(R, i);
        if (i > N-sz) L = max(L, sz-N+i);
        if (L > R++) continue;
        add[L].push_back(A[i]);
        del[R].push_back(A[i]);
    }
    unordered_set<int> cur;
    for (int i = 0; i < sz; ++i) {
        for (int x : del[i])
            cur.erase(x);
        for (int x : add[i]) {
            if (cur.count(x)) return true;
            cur.insert(x);
        }
    }
    return false;
}

ll solve() {
    cin >> N; A.resize(N);
    for (int &x : A) cin >> x;

    int lo = 0, hi = N-1;
    while (lo < hi) {
        int mid = lo + (hi-lo+1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    if (lo == 0) return -1;
    return lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
