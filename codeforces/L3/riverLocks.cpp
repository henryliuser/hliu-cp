// https://codeforces.com/problemset/problem/1700/D
// dp[i] = cost to fill up to i, opening up to i
//  t[i] = max( dp[i], ceil(ps[N]/i) )
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	vector<int> ps(N+1), dp(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> ps[i];
		ps[i] += ps[i-1];
		dp[i] = max(dp[i-1], (ps[i]+i-1)/i );
	}
	for (int i = 1; i <= N; ++i)
		dp[i] = max(dp[i], (ps[N]+i-1)/i );

	int Q, x; cin >> Q;
	while (Q--) {
		cin >> x;
		int l = 1, r = N+1;
		while (l < r) {
			int m = (l+r) >> 1;
			if (dp[m] <= x) r = m;
			else l = m+1;
		}
		cout << (l == N+1 ? -1 : l) << '\n';
	}
}
