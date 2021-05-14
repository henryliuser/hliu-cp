#include <bits/stdc++.h>
using namespace std;

// bool last[3] = {1,1,1};
string last = "BessieElsieMildred";
bool check(unordered_map<string, int>& c) {
    vector<pair<int, string>> v(3);
    for (auto it : c) v.push_back({it.second, it.first});
    sort(v.begin(), v.end());
    int mx = v[2].first;
    vector<string> now;
    for (int z = 0; z < 3; z++)
        if (v[z].first == mx)
            now.push_back(v[z].second);
    sort(now.begin(), now.end());
    string next = "";
    for (string& s : now) next += s;
    bool ans = false;
    if (next != last) ans = true;
    last = next;
    return ans;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    unordered_map<string, int> cows;
    cows["Mildred"] = 7;
    cows["Elsie"] = 7;
    cows["Bessie"] = 7;

    priority_queue<int, pair<string, int>> pq;
    int N; cin >> N;
    while (N--) {
        int d; cin >> d;
        string c; cin >> c;
        int dif; cin >> dif;
        pq.push({-d, {c,dif}});
    }
    int ans = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cows[p.second.first] += p.second.second;
        ans += check(cows);
    }
    cout << ans << endl;

}
