// copied from editorial.

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int solve() {
    if (A[N-2]-A[0] == N-2 && A[N-1]-A[N-2] > 2) return 2;  // consec then gap
    if (A[N-1]-A[1] == N-2 && A[1]-A[0] > 2) return 2;
    int i = 0, ans = 0;
    for (int j = 0; j < N; ++j) {
        while (i < N-1 && A[i+1]-A[j] <= N-1) ++i;
        ans = max(ans, i-j+1);
    }
    return N-ans;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> N; A.resize(N);
    for (int &x : A) cin >> x;
    sort(begin(A), end(A));
    cout << solve() << "\n";
    cout << max(A[N-2]-A[0], A[N-1]-A[1]) - (N-2) << "\n";
}
