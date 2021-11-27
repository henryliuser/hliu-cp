// easier than i thought.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = array<int, 2>;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N; cin >> N;
    vector<pii> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0];
        A[i][1] = i;
    }
    int ans = 0;
    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i) {
        int diff = A[i][1] - i;
        ans = max(ans, diff);
    }
    cout << 1 + ans << "\n";
}
