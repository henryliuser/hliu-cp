#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    vector<vector<int>> r(2, vector<int>(4));
    for (int z = 0; z < 2; z++)
        for (int a = 0; a < 4; a++)
            cin >> r[z][a];

    int minX = min(r[0][0], r[1][0]);
    int maxX = max(r[0][2], r[1][2]);
    int minY = min(r[0][1], r[1][1]);
    int maxY = max(r[0][3], r[1][3]);
    int maxdif = max(maxX - minX, maxY - minY);
    cout << maxdif * maxdif << endl;

}
