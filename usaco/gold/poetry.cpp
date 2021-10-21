#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

static constexpr int MOD = 1e9 + 7;

ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ll ans = 1;
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    unordered_map<int, ll> count;
    unordered_map<string, ll> lines;
    vector<pii> words(N);
    vector<ll> dp(K+1);
    dp[0] = 1;
    for (int i = 0; i < N; ++i)
        cin >> words[i].f >> words[i].s;

    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j < N; ++j) {
            auto [syl, rhy] = words[j];
            if (syl > i) continue;
            dp[i] = (dp[i] + dp[i-syl] + MOD) % MOD;
            if (i == K)
                count[rhy] = (count[rhy] + dp[i-syl] + MOD) % MOD;
        }
    }

    for (int i = 0; i < M; ++i) {
        string ch; cin >> ch;
        ++lines[ch];
    }

    for (auto ch : lines) {
        ll curr = 0;
        for (auto rhy : count) {
            curr += modPow(rhy.s, ch.s, MOD);
            curr = (curr+MOD) % MOD;
        }
        ans = (ans * curr) % MOD;
    }

    cout << ans << endl;


}
