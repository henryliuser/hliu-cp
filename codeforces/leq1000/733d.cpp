#include <bits/stdc++.h>
using namespace std;

vector<int> solve() {
    int n; cin >> n;
    vector<int> ans(n+1), wish(n);
    for (int& i : wish) cin >> i;
    unordered_map<int, vector<int>> sets;
    set<int> taken, free;

    for (int z = 1; z <= n; ++z)
        free.insert(z);
    for (int z = 1; z <= n; ++z) {
        int w = wish[z];
        sets[w].push_back(z);
        if (free.count(w)) {
            free.erase(w);
            ans[0] += 1;
        }
    }
    set<int, greater<int>> fr2;
    for (auto i : free) fr2.insert(i);
    for (auto w : wish) {
        if (!taken.count(w)) {
            ans.push_back(w);
            taken.insert(w);
        }
        else {
            auto x = fr2.begin();
            ans.push_back(*x);
            fr2.erase(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int w = ans[i];
        if (i == w) {
            for (auto xx : sets[wish[i-1]]) {
                if (xx != i) {
                    swap(ans[i-1], ans[xx-1]);
                }
                break;
            }
        }

    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> v = solve();
        cout << v[0] << endl;
        for (int i = 1; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

}
