// https://cses.fi/problemset/task/2162
// use std::set, N log N
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    set<int> s;
    for (int i = 1; i <= N; ++i)
        s.insert(i);

    auto cur = begin(s);
    for (int i = 0; i < N; ++i) {
        if (++cur == end(s))
            cur = begin(s);
        cout << *cur << ' ';
        if ( (cur = s.erase(cur)) == end(s) )
            cur = begin(s);
    }
}
