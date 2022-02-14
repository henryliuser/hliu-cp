#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
void chmin(int &x, int y) { x = min(x,y); }

vector<int> solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    vector<int> B(N+2);
    for (int i = 0; i < N; ++i)
        B[i+2] = A[i] - B[i-1] - B[i-2];

    int c[3] = {inf, inf, inf};
    for (int i = 0; i < N+2; ++i)
        chmin(c[i%3], B[i]);

    if (-c[0] - c[1] > c[2])
        return {};

    int a[3] = { -c[0], -c[1], c[0]+c[1] };
    for (int i = 0; i < N+2; ++i)
        B[i] += a[i%3];
    return B;
}

int main() {
    auto ans = solve();
    if (ans.empty()) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int x : ans)
            cout << x << " ";
    }
}
