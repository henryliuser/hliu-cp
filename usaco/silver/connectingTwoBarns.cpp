// 2 cases:
// add edge from 0 to cN (component of N)
// add edge from 0 to i, then i to cN for all 1<i<C
// take best
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<bool> seen;
vector<set<ll>> comps;
vector<vector<ll>> adj;

void dfs(int u, set<ll> &s) {
    s.insert(u);
    for (int v : adj[u]) {
        if (seen[v]) continue;
        seen[v] = 1;
        dfs(v, s);
    }
}

void reset() {
    comps.clear();
    seen.assign(N, 0);
    adj.assign(N, vector<ll>());
}

ll cost(int a, int b) {
    if (a == b) return 0ll;
    if (comps[a].size() > comps[b].size())
        swap(a, b);
    auto &s1 = comps[a];
    auto &s2 = comps[b];

    ll dx = INT_MAX;
    for (ll x : s1) {
        auto it = s2.lower_bound(x);
        if (it == end(s2)) --it;
        dx = min(dx, abs(*it - x));
        if (it == begin(s2)) continue;
        dx = min(dx, x - *prev(it));
    }
    return dx * dx;
}

ll solve() {
    cin >> N >> M;
    reset();
    while (M--) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int cN, c = 0;
    for (int i = 0; i < N; ++i) {
        if (seen[i]) continue;
        set<ll> s;
        dfs(i, s);
        if (s.count(N-1)) cN = c;
        comps.push_back(s);
        ++c;
    }
    if (cN == 0) return 0;

    ll ans = LLONG_MAX;
    for (int i = 1; i < c; ++i) {
        ll x = cost(0, i);
        ll y = cost(i, cN);
        ans = min(ans, x+y);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
