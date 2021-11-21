#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

class Group {
public:
	set<pii> s;
	multiset<int> xs, ys;
	int minX = INT_MAX, maxX = -1;
	int minY = INT_MAX, maxY = -1;
	Group() {}
	Group(vector<pii> &cows) {
		for (auto &p : cows)
			add(p);
	}
	void add(pii p) {
		s.insert(p);
		xs.insert(p.f);
		ys.insert(p.s);
		update(p);
	}
	pii pop() {
		auto it = s.begin();
		pii res = *it;
		s.erase(it);
		xs.erase(xs.find(res.f));
		ys.erase(ys.find(res.s));
		update();
		return res;
	}
	ll area() {
		if (s.empty()) return 0;
		ll dx = maxX - minX;
		ll dy = maxY - minY;
		return dx * dy;
	}
	int size() { return s.size(); }
private:
	void update() {
		if (s.empty()) return;
		minX = *xs.begin();
		minY = *ys.begin();
		maxX = *xs.rbegin();
		maxY = *ys.rbegin();
	}
	void update(pii &p) {
		minX = min(minX, p.f);
		minY = min(minY, p.s);
		maxX = max(maxX, p.f);
		maxY = max(maxY, p.s);
	}
};

void setIO() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void sweep(Group &A, Group &B, ll &ans) {
	int N = B.size();
	while (A.size() < N) {
		A.add(B.pop());
		while (B.size() && A.maxX == B.minX)
			A.add(B.pop());
		ll curr = A.area() + B.area();
		ans = min(ans, curr);
	}
}

int main() {
	setIO();
	int N; cin >> N;
	vector<pii> cows(N), invs(N);
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		cows[i].f = x, cows[i].s = y;
		invs[i].f = y, invs[i].s = x;
	}
	Group A, B(cows), C, D(invs);

	ll og = B.area();
	ll ans = LLONG_MAX;
	sweep(A, B, ans);
	sweep(C, D, ans);

	cout << max(0ll, og - ans) << "\n";
}
