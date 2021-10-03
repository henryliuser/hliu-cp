// ! runtime error? on 3 and 7. no idea why
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

int p, c;
int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int N, M, R;
    cin >> N >> M >> R;
    priority_queue<pii> stores;
    vector<int> cows(N), farmers(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i];
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        stores.push( {b, a} );
    }
    for (int i = 0; i < R; ++i)
        cin >> farmers[i];

    sort(begin(cows), end(cows), greater<int>());
    sort(begin(farmers), end(farmers), greater<int>());
    farmers.resize(N);
    vector<ll> pre(N+1);
    for (int i = 1; i <= N; ++i)
        pre[i] = farmers[i-1] + pre[i-1];

    ll sum = 0;
    ll ans = pre[N];
    for (int i = 0; i < N; ++i) {
        int sold = 0;
        int milk = cows[i];
        while (!stores.empty() && sold < milk) {
            pii& st = stores.top();
            int m = min(st.s, milk-sold);
            sum += m * st.f;
            sold += m;
            st.s -= m;
            if (st.s == 0) stores.pop();
        }
        ans = max(ans, sum + pre[N-i-1]);
    }

    cout << ans << endl;
}
