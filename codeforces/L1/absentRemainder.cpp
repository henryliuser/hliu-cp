#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<array<int,2>> ans;
    for (int &x : A) cin >> x;
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < N/2; ++i)
        ans.push_back( {A[i], A[N-1]} );

    for (auto &p : ans)
        cout << p[0] << " " << p[1] << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}
