// https://codeforces.com/contest/1665/problem/C
// easy and fair question im just stupid
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

ll solve() {
    int N; cin >> N;
    vector<int> left(N+1);
    vector<vector<int>> adj(N+1);
    for (int p, i=2; i <= N; ++i) {
        cin >> p;
        adj[p].push_back(i);
    }
    adj[0].push_back(1);
    vector<int> order;
    for (int u = 0; u <= N; ++u) {
        if (!adj[u].empty())
            order.push_back(adj[u].size());
    }
    sort( all(order) );

    int t;
    multiset<int> ms;
    int O = order.size();
    for (t = 1; t <= O; ++t)
        ms.insert( t + adj[order[O-t]].size()-1 );

    for (t = O; t <= N; ++t) {
        while (!ms.empty() && *begin(ms) <= t)
            ms.erase(begin(ms));

        if (!ms.empty()) {
            auto it = prev(end(ms));
            int b = *it;
            ms.erase(it);
            ms.insert(b-1);
        }
        if (ms.empty()) break;
    }
    return t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
