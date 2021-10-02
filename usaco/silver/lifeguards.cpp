// Instructive question. Record cows start and end as separate "events".
// Process events in order, keep track of which cow is active.
// if only one cow active, then add to their alone time
// return total - min(alone)

#include <bits/stdc++.h>
using namespace std;

struct Event {
    int time, cow;
    bool isStart;
};

bool cmp(Event& e1, Event& e2) {
    return e1.time < e2.time;
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        events.push_back( {a, i, true} );
        events.push_back( {b, i, false} );
    }
    sort(begin(events), end(events), cmp);

    int prev = 0;
    int total = 0;
    set<int> curr;
    vector<int> one(n);
    for (auto e : events) {
        int t = e.time;
        if (curr.size() > 0)
            total += t - prev;
        if (curr.size() == 1)
            one[*curr.begin()] += t - prev;
        if (e.isStart) curr.insert(e.cow);
        else curr.erase(e.cow);
        prev = t;
    }
    int m = *min_element(begin(one), end(one));
    cout << total - m << endl;

}
