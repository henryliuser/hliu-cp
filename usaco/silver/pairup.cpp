#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second

int main() {
    ll ans = 0;
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int N; cin >> N;
    vector<pll> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i].s >> cows[i].f;

    sort(cows.begin(), cows.end());
    int i = 0, j = N-1;
    while (i <= j) {
        ll &a = cows[i].f, &c = cows[j].f;
        ll &b = cows[i].s, &d = cows[j].s;
        if (i == j) {
            ans = max(ans, a+c);
            break;
        }
        int m = min(b,d);
        ans = max(ans, a+c);
        b -= m, d -= m;
        i += (!b);
        j -= (!d);
    }
    cout << ans << endl;

}
