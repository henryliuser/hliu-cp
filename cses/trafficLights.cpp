// https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct SortedIntervals {
    using iv = pair<int, int>;
    set<iv> ivals;
    map<int, int> len;
    void split(int p) {
        auto it = ivals.upper_bound( {p,-1} );
        auto [l,r] = *(--it);
        add(l, p);  // left
        add(p, r);  // right
        del(it);
    }
    inline void cnt(int x, int v) {
        if ( (len[x] += v) <= 0 )
            len.erase(x);
    }
    inline void add(int l, int r) {
        ivals.insert( {l,r} );
        cnt(r-l, 1);
    }
    inline void del(set<iv>::iterator it) {
        cnt(it->second - it->first, -1);
        ivals.erase(it);
    }
    SortedIntervals(int l, int r) {
        add(l, r);
        ivals.insert( {l-1, l-1} );
        ivals.insert( {r+1, r+1} );
    }
    inline int get() {
        return len.rbegin()->first;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, n;
    cin >> x >> n;
    SortedIntervals ivals(0, x);
    for (int p, i=0; i < n; ++i) {
        cin >> p;
        ivals.split(p);
        cout << ivals.get() << ' ';
    }
}
