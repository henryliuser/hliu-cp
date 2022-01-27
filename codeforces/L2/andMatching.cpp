// https://codeforces.com/contest/1631/problem/C
// 1. the only -1 case is N = 4, K = 3
// 2. you can always take (K, 1111...) to be a pair, and match 0's for the rest
// 1111... -> N-1 because N is a power of 2
//     EDGE CASE: if (K == N-1), then do (N-2 & 111..), (1 & 3), then match 0's
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

int NOT(int x) {
    int res = 0;
    int y = log2(x);
    for (int b = y; b >= 0; --b) {
        if (x & (1 << b)) continue;
        else res |= (1<<b);
    }
    return res;
}

vector<pi> solve() {
    vector<pi> ans;
    int N, K; cin >> N >> K;
    if (N == 4 && K == 3) return {};
    set<int> s;
    for (int x = 0; x < N; ++x)
        s.insert(x);
    if (K != N-1) {
        s.erase(K);
        s.erase(N-1);
        ans.push_back( {K, N-1} );
    }
    else {
        s.erase(N-2);
        s.erase(N-1);
        s.erase(1);
        s.erase(3);
        ans.push_back( {N-2, N-1} );
        ans.push_back( {1, 3} );
    }
    while (!s.empty()) {
        int a = *prev(end(s));
        int b = NOT(a);
        if (!s.count(b)) {
            b = 0;
        }
        ans.push_back( {a,b} );
        s.erase(a);
        s.erase(b);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        auto s = solve();
        if (s.empty()) cout << "-1\n";
        else {
            for (auto &p : s)
                cout << p[0] << " " << p[1] << '\n';
        }
    }
}
