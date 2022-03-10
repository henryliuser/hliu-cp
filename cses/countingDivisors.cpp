// https://cses.fi/problemset/task/1713
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXN = 1000001;

int ndiv[MXN]{};
int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int x = 1; x <= MXN; ++x)
        for (int y = x; y <= MXN; y += x)
            ++ndiv[y];

    int N; cin >> N;
    for (int x; N--;) {
        cin >> x;
        cout << ndiv[x] << '\n';
    }

}
