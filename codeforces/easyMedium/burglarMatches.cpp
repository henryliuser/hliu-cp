#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    for (int z = 0; z < m; z++) {
        int a, b; cin >> a >> b;
        pq.push({b, a});
    }
    int ans = 0;
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int num = p.second;
        if (num < n) {
            ans += num * p.first;
            n -= num;
        }
        else {
            ans += n * p.first;
            break;
        }
    }
    cout << ans << endl;

}
