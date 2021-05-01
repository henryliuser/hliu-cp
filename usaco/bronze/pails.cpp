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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, M; cin >> X >> Y >> M;
    int ans = 0;
    for (int tx = 0; tx < M/X + 1; tx++) {
        for (int ty = 0; ty < M/Y + 1; ty++) {
            int temp = tx*X + ty*Y;
            if (temp > M) break;
            ans = max(ans, temp);
        }
    }
    cout << ans;

}
