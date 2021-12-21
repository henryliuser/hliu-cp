// https://codeforces.com/contest/1609/problem/C
// nice 2p question.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e6+1;

vector<int> spf;

void sieve(int N, vector<int> &spf) {
    spf.resize(N+1);
    spf[0] = spf[1] = -1;
    for (int i = 3; i <= N; i += 2) spf[i] = i;
    for (int i = 2; i <= N; i += 2) spf[i] = 2;  // avoid lots of % later
    for (int i = 3; i*i <= N; i += 2) {
        if (spf[i] != i) continue;
        for (int j = i*i; j <= N; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
}

ll solve() {
    ll ans = 0;
    int N, E; cin >> N >> E;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    vector<vector<ll>> adj(E);
    for (int i = 0; i < E; ++i) {
        for (int j = 0; j < N; ++j) {
            int idx = i + E*j;
            if (idx >= N) break;
            ll x = A[idx];
            adj[i].push_back(x);
        }
    }
    for (int k = 0; k < E; ++k) {
        auto &B = adj[k];
        B.push_back(4);  // dummy element
        int sz = B.size();
        int i = 0, pr = -1;
        for (int j = 0; j < sz; ++j) {
            ll x = B[j];
            if (x == 1) continue;
            if (pr == -1 && spf[x] == x)
                pr = j;
            else {
                while (i < j && pr != -1) {
                    ll y = B[i++];
                    if (y == 1)
                        ans += j - pr;
                    else if (spf[y] == y) {
                        ans += j - 1 - pr;
                        break;
                    }
                }
                pr = -1;
                if (spf[x] == x) pr = j;
                else i = j+1;
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    sieve(MXN, spf);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
