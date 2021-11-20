#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(n+1) {}
    void update(int i, int x) {
        for (++i; i <= N; i += i & -i)
            bit[i] += x;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans = 0;
    int N; cin >> N;

    BIT ft(N+1);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        int ge = ft.query(N) - ft.query(x);
        ans += ge;
        ft.update(x, 1);
    }
    cout << ans << "\n";
}
