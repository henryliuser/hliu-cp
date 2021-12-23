// https://codeforces.com/contest/1619/problem/D
// nice problem. Reduce further
// got the binary search approach right away but need
// some more reduction thinking to get the check in O(MN)
// only 2 conditions:
// 1. all friends must find a gift >= g
// 2. there must be some store with 2 gifts >= g
//  ^^^ by pidgeonhole principle
// this simplified check gives 1e5 log 1e9
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, N;
vector<vector<ll>> p;

bool check(ll g) {
    bool pidgeon = false;
    vector<bool> found(N);  // each friend must have some >= g
    for (int i = 0; i < M; ++i) {  // at least 1 shop must have 2 >= g
        int c = 0;  // if any shop has > 1, 1st condition satisfied
        for (int j = 0; j < N; ++j) {
            if (p[i][j] < g) continue;
            found[j] = true;
            ++c;
        }
        if (c > 1) pidgeon = true;
    }
    if (!pidgeon && N > 1) return false;
    for (bool b : found)
        if (!b) return false;
    return true;
}

int solve() {
    cin >> M >> N;
    p.assign(M, vector<ll>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> p[i][j];

    ll lo = 1, hi = 1e9;
    while (lo < hi) {
        ll mid = lo + (hi-lo+1) / 2ll;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
