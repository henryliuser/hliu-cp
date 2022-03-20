// https://www.codechef.com/START30B/problems/PRESUFOP
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

ll solve() {
    int N; cin >> N;
    vector<int> A(N), D(N);
    for (int &x : A) cin >> x;

    vector<int> cur;
    vector<vector<int>> comps;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        D[i] -= A[i];
        if (D[i] < 0) return -1;
        if (D[i] == 0) {
            vector<int> tmp = cur;
            comps.push_back(tmp);
            cur.clear();
        }
        else cur.push_back(D[i]);
    }
    comps.push_back(cur);

    ll ans = 0;
    for (auto &v : comps)
        ans += *max_element(all(v));

    return ans;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
