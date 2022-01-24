#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p;
vector<int> all;
set<int> res;

void dfs(int i, int cur) {
    if (i >= all.size()) return;
    res.insert(cur);
    dfs(i+1, cur);
    res.insert(cur^all[i]);
    dfs(i+1, cur^all[i]);
}

int main() {
    int N = 5;
    p = (1<<N)-1;
    // for (int i = 1; i <= 3; ++i) {
    //     bitset<3> bs(i);
    //     cout << bs << '\n';
    //     all.push_back(i);
    //     // cout << bs << '\n';
    // }
    all.push_back(6);
    all.push_back(7);
    all.push_back(15);
    all.push_back(13);
    // all.push_back(2);
    cout << "\n\n";
    dfs(0, 0);
    cout << res.size() << '\n';
    for (auto &b : res) {
        printf("%-3d", b);
        cout << bitset<4>(b) << '\n';
    }
}
