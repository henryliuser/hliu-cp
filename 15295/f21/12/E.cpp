#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e6+3;

int sum[MXN];

string solve() {
    int x; cin >> x;
    if (sum[x] >  x) return "abundant";
    if (sum[x] <  x) return "deficient";
    return "perfect";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 1; i <= MXN; ++i)
        for (int j = i+i; j <= MXN; j += i)
            sum[j] += i;

    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";

}
