// https://cses.fi/problemset/task/1164
// interpret as intervals question.
// greedily take and logically restore rooms
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int, 2>;
const int INF = 1e9+5;
#define all(x) begin(x), end(x)

int main() {
    int N; cin >> N;
    priority_queue<int> rooms;
    for (int i = 1; i <= N; ++i)
        rooms.push(-i);

    vector<pi> st(N), en(N);
    for (int i = 0; i < N; ++i) {
        cin >> st[i][0] >> en[i][0];
        st[i][1] = en[i][1] = i;
    }
    int mx = 0;
    vector<int> ans(N);
    sort(all(st)), sort(all(en));
    for (int i=0, j=0; i < N; ++i) {
        auto [s,q] = st[i];
        while (j < N && en[j][0] < s) {
            int g = en[j++][1];
            rooms.push(-ans[g]);  // restore the room
        }
        ans[q] = -rooms.top();
        mx = max(mx, ans[q]);
        rooms.pop();
    }
    cout << mx << '\n';
    for (int x : ans)
        cout << x << ' ';

}
