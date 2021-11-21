#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> D;

bool check(int g) {
	int t = 0;
	multiset<int> curr;
	for (int i = 0; i < N; ++i) {
		curr.insert( D[i] + t );
		if (curr.size() > g) {
			auto it = curr.begin();
			t = *it;
			while (*it == t) {
				t = *it;
				curr.erase(it);
				it = curr.begin();
			}
			t = *it;
		}
	}
	t = *curr.rbegin();
	return t <= T;
}

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> T; D.resize(N);
	for (int &x : D) cin >> x;

	int lo = 1, hi = N;
	while (lo < hi) {
		int mid = lo + (hi-lo) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << lo << "\n";
}
