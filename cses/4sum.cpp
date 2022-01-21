// https://cses.fi/problemset/task/1642/
// sum all pairs then run two sum
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pi(x) array<ll, x>

int main() {
    vector<int> ans;
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    map<int, pi(2)> mp;
    for (int i = 0; i < N-1; ++i)
        for (int j = i+1; j < N; ++j)
            mp[ A[i]+A[j] ] = {i,j};

    for (int i = 0; i < N-1; ++i)
        for (int j = i+1; j < N; ++j) {
            ll s = A[i] + A[j];
            ll t = X - s;
            if (!mp.count(t)) continue;
            pi(2) p = mp[t];
            int k = p[0], l = p[1];
            if (i == k || i == l) continue;
            if (j == k || j == l) continue;
            ans = {i,j,k,l};
            goto done;
        }

    done:
    if (ans.empty()) cout << "IMPOSSIBLE\n";
    else for (int x : ans)
        cout << x+1 << " ";
}
