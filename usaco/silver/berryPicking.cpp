// http://www.usaco.org/index.php?page=viewproblem2&cpid=990
// incredibly instructive
// use math to fix some condition
// which makes verification much much easier.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int N, K, M = 0, ans = 0;
    cin >> N >> K;
    vector<int> B(N);
    for (int &x : B) cin >> x;
    sort(begin(B), end(B));
    for (int b = 1; b <= 1000; ++b) {
        vector<int> T = B;
        int f = 0;  // num full
        for (int i = N-1; i >= 0; --i) {
            f += T[i] / b;
            T[i] %= b;
        }
        if (f < K/2) break;
        if (f >= K) ans = max(ans, b*K/2);
        else {
            int curr = b * (f-K/2);
            sort(begin(T), end(T));
            for (int i = 0; i < N && i < K-f; ++i)
                curr += T[N-i-1];
            ans = max(ans, curr);
        }
    }
    cout << ans << "\n";
}

// doesn't work. (5/11)
// split in half 1 by 1, until score stops improving
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
multiset<int> B;

ll score(multiset<int> &ms) {
    ll c = 1, res = 0;
    for (auto it = ms.rbegin(); it != ms.rend(); ++it) {
        if (c > K) break;
        if (c > K/2) res += *it;
        ++c;
    }
    return res;
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        B.insert(x);
    }
    while (B.size() < K) B.insert(0);

    ll ans = 0;
    while (1) {
        int g = *B.rbegin();
        multiset<int> T = B;
        T.erase(prev(end(T)));
        T.insert(g/2);
        T.insert(g/2 + (g%2));
        ll s = score(T);
        if (s < ans) break;
        swap(B, T);
        ans = s;
    }

    cout << ans << "\n";
}
*/
