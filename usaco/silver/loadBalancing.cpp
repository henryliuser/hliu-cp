#include <bits/stdc++.h>
using namespace std;

struct Cow { int x, y; };

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N; scanf("%d", &N);
    vector<Cow> cows(N, Cow{});
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &(cows[i].x), &(cows[i].y));

    sort(cows.begin(), cows.end(), [](auto& a, auto& b) {
        return a.x < b.x;
    });

    for (int y = 0; y < N; y += 2) { // horizontal
        int counts[4] = {0,0,0,0};   // quadrant counts
        for (auto& c : cows) {
            if (c.y > y) counts[0]++;
            else counts[3]++;
        }
        int x = 0;
        while (x < )
    }


}
