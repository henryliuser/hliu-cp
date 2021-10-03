// fails final case. Idk.

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int N, off;
unordered_map<int, pii> mp;

struct Event {
    int x, y, id;
    bool isEnd;
};

bool cmp(const Event& a, const Event& b) {
    return a.x < b.x;
}

int rotHeight(int i) {
    return mp[i].f + mp[i].s;
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    cin >> N;
    vector<Event> events;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        events.push_back( {x-y, 0, i, 0, 0} );
        events.push_back( {x+y, 0, i, 0, 1} );
        mp[i] = {x,y};
    }
    sort(events.begin(), events.end(), cmp);
    off = (events[0].x < 0) ? (-events[0].x) : 0;
    int ans = 0;
    multiset<pii> curr;
    for (auto& e : events) {
        int rh = rotHeight(e.id);
        if (e.isEnd)
            curr.erase(curr.find( {rh, e.id} ));
        else {
            ans += (curr.empty() || (curr.rbegin()->f < rh));
            curr.insert( {rh, e.id} );
        }
    }
    cout << ans << endl;
}
