#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll N, T;
vector<ll> A;

bool check(ll g) {
	ll res = 0;
	for (int i = 0; i < N; ++i)
		res += g / A[i];
	return res >= T;
}

int main() {
	cin >> N >> T; A.resize(N);
	for (ll &x : A) cin >> x;

	ll lo = 1, hi = LLONG_MAX-100;
	while (lo < hi) {
		ll mid = lo + (hi-lo) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << lo << "\n";
}
