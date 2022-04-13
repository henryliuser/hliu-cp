// https://atcoder.jp/contests/abc247/tasks/abc247_e
// "sliding window"-ish
// just keep track of the first X and first Y to the left of current R
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

ll solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    int j = 0;
    ll ans = 0;
    int lx = -1, ly = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] == X) lx = i;
        if (A[i] == Y) ly = i;
        if (A[i] < Y || A[i] > X) {
            j = i+1;
            lx = ly = -1;
        }
        if (lx != -1 && ly != -1) {
            int k = min(lx, ly);
            ans += k - j + 1;
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << solve() << '\n';
}
