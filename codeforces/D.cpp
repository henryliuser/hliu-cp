#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p;
int N;
set<ll> cur;

void upd(ll y) {
    ll x = y;
    ll repl = -1;
    while (!cur.empty() && x) {
        if (x % 4 == 0) x /= 4;
        else if (x % 2) x /= 2;
        else break;
        if (cur.count(x)) repl = x;
    }
    if (repl == -1) cur.insert(y);
}

ll solve() {
    cin >> N >> p;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    sort(begin(A), end(A));

    cur.clear();
    for (ll x : A) upd(x);

    for (ll x : cur)
        printf("%d ", x);
        cout << '\n';


}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
