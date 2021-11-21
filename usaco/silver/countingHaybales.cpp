#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	vector<int> A(N);
	for (int &x : A) cin >> x;
	sort(begin(A), end(A));
	while (Q--) {
		int l, r; cin >> l >> r;
		auto R = upper_bound(begin(A), end(A), r);
		auto L = lower_bound(begin(A), end(A), l);
		int gap = R - L;
		cout << gap << "\n";
	}
}
