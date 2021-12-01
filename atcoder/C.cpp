#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = array<int, 2>;

int main() {
    string a, b; cin >> a >> b;
//    if (a.size() < b.size()) swap(a,b);
    multiset<int> ms;
    for (char ch : a) ms.insert(ch-'0');
    sort(begin(b), end(b));

    deque<int> ans[2];
    vector<pii> carries, nines;
    vector<bool> used(b.size());
    for (int i = 0; i < b.size(); ++i) {
        int x = b[i] - '0';
        int t = 10 - x;
        auto it = ms.lower_bound(t);
        if (it == end(ms)) continue;
        carries.push_back( {*it, x} );
        ms.erase(it);
        used[i] = 1;
        break;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (used[i]) continue;
        int x = b[i] - '0';
        int t = 9 - x;
        if (!ms.count(t)) continue;
        auto it = ms.lower_bound(t);
        nines.push_back( {*it, x} );
        ms.erase(it);
        used[i] = 1;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (used[i]) continue;
        int x = b[i] - '0';
        int t = 10 - x;
        auto it = ms.lower_bound(t);
        if (it == end(ms)) continue;
        carries.push_back( {*it, x} );
        ms.erase(it);
        used[i] = 1;
    }

    for (pii &p : carries) {
        ans[0].push_front(p[0]);
        ans[1].push_front(p[1]);
        // if (nines.empty()) continue;
        // pii &n = nines.back();
        // ans[0].push_front(n[0]);
        // ans[1].push_front(n[1]);
        // nines.pop_back();
    }
    for (pii &p : nines) {
        ans[0].push_front(p[0]);
        ans[1].push_front(p[1]);
    }
    multiset<int> rm;
    for (int i = 0; i < b.size(); ++i) {
        if (used[i]) continue;
        rm.insert(b[i]-'0');
    }
    if (!rm.empty())
        for (auto it = rm.rbegin(); it != rm.rend(); ++it)
            ans[1].push_front(*it);
    if (!ms.empty())
        for (auto it = ms.rbegin(); it != ms.rend(); ++it)
            ans[0].push_front(*it);

    for (int x : ans[0]) cout << x; cout << "\n";
    for (int x : ans[1]) cout << x; cout << "\n";


}
