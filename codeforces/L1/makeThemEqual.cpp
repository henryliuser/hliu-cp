// https://codeforces.com/contest/1633/problem/D
// calculate min ops to reach B[i] then knapsack
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> dist(1001, -1);
void bfs() {
    queue<int> q;
    dist[1] = 0;

    q.push(1);
    int depth = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int x = q.front();
            q.pop();
            for (int i = 1; i*i <= x; ++i) {
                ll y = x + x/i;      // i and x/i are the
                ll z = x + x/(x/i);  // unique divisor candidates
                if (y <= 1001 && dist[y] == -1)
                    q.push(y),
                    dist[y] = depth+1;
                if (z <= 1001 && dist[z] == -1)
                    q.push(z),
                    dist[z] = depth+1;
            }
        }
        ++depth;
    }
}

ll solve() {
    ll ans = 0, mx = 0;
    int N, K; cin >> N >> K;
    vector<ll> B(N), C(N);
    vector<ll> dp(K+1, -1);
    for (ll &x : B) { cin >> x; mx = max(mx, x); }
    for (ll &x : C) cin >> x;

    vector<int> W(N);
    for (int i = 0; i < N; ++i)
        W[i] = dist[B[i]];

    dp[0] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = K; j >= 0; --j) {
            if (dp[j] == -1) continue;
            if (j+W[i] > K) continue;
            ll &r = dp[ j+W[i] ];
            r = max(r, dp[j] + C[i]);
            ans = max(ans, r);
        }
    return ans;
}

int main() {
    bfs();
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
