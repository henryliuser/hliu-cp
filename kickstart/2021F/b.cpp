#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll ans = 0;
    int D, N, K; cin >> D >> N >> K;
    vector<vector<int>> days(D+2);
    for (int i = 0; i < N; ++i) {
        int h, s, e; cin >> h >> s >> e;
        days[s].push_back(h);
        days[e+1].push_back(-h);
    }
    ll sum = 0;
    multiset<int> curr, reserve;
    for (auto& d : days) {
        for (int h : d) {
            if (h > 0) {
                auto minC = curr.begin();
                if (curr.size() < K) {
                    curr.insert(h);
                    sum += h;
                }
                else if (h > *minC) {
                    sum += h - *minC;
                    reserve.insert(*minC);
                    curr.erase(minC);
                    curr.insert(h);
                }
                else reserve.insert(h);

            }
            if (h < 0) {
                auto it = curr.find(-h);
                auto itR = reserve.find(-h);
                if (it != curr.end()) {  // if h in curr
                    curr.erase(it);
                    if (!reserve.empty()) {
                        auto r = prev(reserve.end());
                        curr.insert(*r);
                        sum += *r;
                        reserve.erase(r);
                    }
                    sum += h;  // -h
                }
                else if (itR != reserve.end()) {
                    reserve.erase(itR);
                }
            }
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

}
