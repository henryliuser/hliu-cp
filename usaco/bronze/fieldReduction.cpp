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
	pii pop(bool pmin=true) {
		auto it = (pmin) ? s.begin() : prev(s.end());
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
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void eval(int pm, Group &A, Group &B, ll &ans) {
	vector<pii> a, b;
	if (pm == 0) a.push_back( A.pop() );
	if (pm == 1) a.push_back( A.pop(0) );
	if (pm == 2) b.push_back( B.pop() );
	if (pm == 3) b.push_back( B.pop(0) );
	ans = min({ ans, A.area(), B.area() });
	for (pii c : a) A.add(c);
	for (pii c : b) B.add(c);
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

	ll ans = LLONG_MAX;
	Group A(cows), B(invs);
	for (int i = 0; i < 4; ++i)
		eval(i, A, B, ans);

	cout << ans << "\n";

}
