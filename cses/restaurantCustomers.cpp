#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int main() {
    int a, b;
    int ans = 0;
    int n; cin >> n;
    vector<pii> custs(n);
    for (int i = 0; i < n; ++i)
        cin >> custs[i].f >> custs[i].s;
    sort(custs.begin(), custs.end());
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        tie(a, b) = custs[i];
        // printf("%d %d\n",a,b);
        while (!pq.empty() && a > -pq.top())
            pq.pop();
        pq.push(-b);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << endl;
}
