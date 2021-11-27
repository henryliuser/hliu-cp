// https://codeforces.com/problemset/problem/1472/E
#include <bits/stdc++.h>
using namespace std;
using tup = array<int, 3>;

void solve() {
	int N; cin >> N;
	vector<tup> A(N), B(N);
	vector<int> pmW(N), pmH(N), ans(N,-1);
	for (int i = 0; i < N; ++i) {
		int h, w; cin >> h >> w;
		A[i] = {h,w,i};
		B[i] = {w,h,i};
	}
	sort(begin(A), end(A));
	sort(begin(B), end(B));
	for (int i = 1; i < N; ++i) { // prefix mins, but with index
		int pw = pmW[i-1];
		if (A[pw][1] < A[i][1]) pmW[i] = pmW[i-1];
		else pmW[i] = i;

		int ph = pmH[i-1];
		if (B[ph][1] < B[i][1]) pmH[i] = pmH[i-1];
		else pmH[i] = i;
	}

	for (int i = 0; i < N; ++i) {
		tup t = {A[i][0], 0, 0};
		auto it1 = lower_bound(begin(A), end(A), t);
		if (it1 != begin(A)) {
			int z = prev(it1) - begin(A);
			int mw = A[pmW[z]][1];
			if (mw < A[i][1]) ans[A[i][2]] = A[pmW[z]][2] + 1;
		}
		auto it2 = lower_bound(begin(B), end(B), t);
		if (it2 == begin(B)) continue;

		int j = prev(it2) - begin(B);
		int mh = B[pmH[j]][1];
		if (mh < A[i][1]) ans[A[i][2]] = B[pmH[j]][2] + 1;
	}
	for (int i = 0; i < N; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--)
		solve();
}
