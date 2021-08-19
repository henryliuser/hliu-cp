// no idea why it fails case 2 on usaco grader. Works locally.
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int ans = 0;
    int N; cin >> N;
    vector<int> paint(N), state(N);  // state[i] {0:unseen, 1:open, -1:closed}
    vector<vector<int>> idx(N);
    for (int z = 0; z < N; ++z) {
        int x; cin >> x;
        paint[z] = x;
        idx[x].push_back(z);
    }
    int curr = 0;
    vector<int> stack;
    for (int z = 0; z < N; ++z) {
        int col = paint[z];
        if (col == 0) {
            if (stack.size() > 0) {ans = -1; break;}
            continue;
        }
        if (state[col] == 0) {
            state[col] = 1;  // set to open
            stack.push_back(col);
            ans = max(ans, ++curr);
        }
        if (z == idx[col].back()) {  // final appearance
            if (col != stack.back()) {ans = -1; break;}
            stack.pop_back();
            state[col] = -1;
            --curr;
        }
    }
    cout << ans << endl;


}
