#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using cow = tuple<int, int, int>;
#define f first
#define s second

int ax, ay, ai;
int bx, by, bi;
vector<int> blame;
vector<unordered_set<int>> stops;

int dfs(int u) {
    if (blame[u] != -1)
        return blame[u];
    int res = 1;
    for (int v : stops[u])
        res += dfs(v);
    blame[u] = res;
    return res;
}

int main() {
    int N; cin >> N;
    vector<cow> east, north;
    stops.resize(N+1);
    blame.assign(N+1, -1);
    vector<int> stoppedAt(N+1, -1);
    vector<pii> stoppedBy(N+1, {-1,-1});
    for (int i = 1; i <= N; ++i) {
        char c; cin >> c;
        cin >> ax >> ay;
        if (c == 'E') east.emplace_back(-ax,ay,i);
        if (c == 'N') north.emplace_back(ax,ay,i);
    }
    sort(begin(east), end(east));
    sort(begin(north), end(north));
    for (cow &c : east) {
        tie(ax, ay, ai) = c;
        ax = -ax;
        cow tmp = {ax, 0, 0};
        auto it = lower_bound(begin(north), end(north), tmp);
        for (; it != end(north); ++it) {
            tie(bx, by, bi) = *it;
            if (by > ay) continue;
            int sa = stoppedAt[bi];
            if (sa != -1 && sa < ay) continue;  // edge case
            // compare E to N
            int dx = bx - ax;
            int dy = ay - by;
            if (dx == dy) continue;
            if (dy > dx) {
                int nt = dy - dx;
                pii &sb = stoppedBy[bi];
                if (sb.f == -1 || nt < sb.s) {
                    stoppedAt[bi] = ay-1;
                    stops[ai].insert(bi);
                    if (sb.f != -1)
                        stops[sb.f].erase(bi);
                    stoppedBy[bi] = {ai, nt};
                }
            }
            if (dy < dx) {
                stoppedAt[ai] = bx-1;
                stops[bi].insert(ai);
                break;
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << dfs(i)-1 << endl;

}
