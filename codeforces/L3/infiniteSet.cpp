// https://codeforces.com/contest/1635/problem/D
// great question.
// there will be a lot of overlap. Which ones will overlap?
// interpret each number as binary number.
// transformation as are as follows:
// 2x+1 <-> x += "1"
// 4x   <-> x += "00"
// transformations of these type will not clash,
// because one ends in "1" other ends in "0".
// but if two x's have the same prefix, they will clash
// sort A and delete the clashing ones.
// for each "root" we want the minimum prefix
// u can check if you've encountered a root in log A[i] time
// by repeatedly dividing 4 and dividing 2 as appropriate
// let dp[i] = # of elements of s, with binary repr length i
// dp[i] = dp[i-1] + dp[i-2] (fibonacci)
// because for every element with length i-1, you can apply 2x+1 to get
// a new unique number of length i. We know it's unique because
// all of our roots have unique prefixes. same logic applies for 4x
// finally, initialize dp with the counts of the root lengths,
// then the answer is the sum across dp from i=1 to i=p.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 1e9+7;
const int MXN = 2e5+5;

int N, p;
set<ll> cur;
ll dp[MXN];

ll add(ll x, ll y) {
    return ((x+=y) >= Q) ? x-Q : x;
}

void upd(ll y) {
    ll x = y;
    while (x && !cur.empty()) {
        if (x % 4 == 0) x /= 4;
        else if (x % 2) x /= 2;
        else break;
        if (cur.count(x)) return;
    }
    cur.insert(y);
}

int lg(ll x) {
    int r = 0;
    while (x) ++r, x >>= 1;
    return r;
}

ll solve() {
    cin >> N >> p;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    sort(begin(A), end(A));
    for (ll x : A) upd(x);

    ll ans = 0;
    for (ll x : cur) ++dp[lg(x)];
    for (int i = 1; i <= p; ++i) {
        ll s1 = dp[i-1];
        ll s2 = (i>=2) ? dp[i-2] : 0;
        ll y = add(s1, s2);
        dp[i] = add(dp[i], y);
        ans = add(ans, dp[i]);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(dp, 0, sizeof dp);
    cout << solve() << '\n';
}
