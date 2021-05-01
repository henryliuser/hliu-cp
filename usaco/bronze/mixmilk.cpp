#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <math.h>

using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int caps[3], milks[3];
    for (int z = 0; z < 3; z++) {
        cin >> caps[z];
        cin >> milks[z];
    }
    for (int z = 0; z < 100; z++) {
        int C = z%3, N = (z+1)%3;
        int t = milks[C];
        int diff = caps[N] - milks[N];
        if (diff >= t) {
            milks[C] = 0;
            milks[N] += t;
        }
        else {
            milks[C] -= diff;
            milks[N] += diff;
        }

    }
    for (int a = 0; a < 3; a++)
        cout << milks[a] << endl;

}
