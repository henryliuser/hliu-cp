#include <bits/stdc++.h>
using namespace std;

void setIO() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	setIO();
	int N, K; cin >> N >> K;
	vector<int> A(N);
	for (int &x : A) cin >> x;
	sort(begin(A), end(A));

	int i = 0, ans = 0;
	for (int j = 0; j < N; ++j) {
		int curr = A[j] - A[i];
		while (curr > K) curr = A[j] - A[++i];
		ans = max(ans, j-i+1);
	}

	cout << ans << "\n";

}
