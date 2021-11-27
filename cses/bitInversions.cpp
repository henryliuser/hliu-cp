#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tup = array<int, 3>;

int main() {
    int m; string s;
    cin >> s >> m;
    int n = s.size();
    s.push_back("?");
    set<tup> groups, byLen;
    int left = 0;
    for (int i = 1; i <= n; ++i) {
        char ch = s[i];
        if (ch != s[i-1]) {
            int len = i - left;
            groups.insert( {left, i-1, len} );
            byLen.insert( {len, left, i-1} );
            left = i;
        }
    }
    while (m--) {
        int i; cin >> i;
        tup tmp = {i, 0, 0};
        auto it = groups.lower_bound(tmp);
        if ((*it)[0] != i) it = prev(it);
        
        // check if bound, then split/join
    }

}
