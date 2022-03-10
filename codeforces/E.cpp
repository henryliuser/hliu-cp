// stop bagholding, < 20 days.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()

ll N, D;

ll solve() {
    cin >> N >> D;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    A.push_back(D);

    ll mu = 1e18;
    multiset<pl> gaps;
    vector<ll> rest(N+1);

    multiset<ll> test;
    for (int i = 1; i <= N; ++i) {
        ll dx = A[i] - A[i-1] - 1;
        gaps.insert( {dx, i} );
        rest[i] = dx;
        mu = min(mu, dx);
        test.insert(dx);
    }
    set<ll> occ( all(A) );

    ll ans = *test.begin();
    for (int i = 1; i <= N; ++i) {
        bool imin = (rest[i] == u);
        bool lmin = (i+1<N && rest[i+1] == u);
        if (!imin && !lmin) continue;
        // try 3 options
        // jump to middle of biggest gap
        // jump to 1 if not taken
        // jump to d if not taken
        auto it = gaps.rbegin();
        if (it->second == i) ++it;
        if (it == gaps.rend()) continue;
        int j = it->second;
        ll dx = it->first / 2;
        ll d = A[j] - dx;
        for (ll x : {d-1, d, d+1}) {
            if (j == 0) continue;
            if (occ.count(x)) continue;
            if (1 <= x && x <= D) {
                ll a,b,c;
                vector<ll> re;
                a = rest[i+1];
                b = rest[i];
                c = rest[j];
                for (ll q : {a,b,c}) {
                    test.erase(test.find(q));
                    re.push_back(q);
                }
                ll a = A[j] - x - 1;
                ll b = x - A[j-1] - 1;
                ll c = A[i+1] - A[i-1] - 1
                for (ll q : {a,b,c})
                    test.insert(q);
                ans = max(ans, *test.begin());
                for (ll q : {a,b,c})
                    test.erase(test.find(q));
                for (ll q : re)
                    test.insert(q);
            }
            else continue;
        }
        if (i+2 > N+1) continue;
        ll a = A[i+1] - A[i] - 1;
        ll b = A[i] - A[i-1] - 1;
        ll c = A[1] - A[0] - 1;
        vector<ll> re;
        for (ll q : {a,b,c}) {
            test.erase(test.find(q));
            re.push_back(q);
        }
        a = A[i+1] - A[i-1] - 1;
        b = D - A[N] - 1;
        c = A[i+2] - A[i] - 1;
        for (ll q : {a,b,c})
            test.insert(q);
        ans = max(ans, *test.begin());
        for (ll q : {a,b,c})
            test.erase(test.find(q));
        for (ll q : re)
            test.insert(q);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
